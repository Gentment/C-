#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define CHECK(q) if((q) == false) {return false;}
class TcpSocket
{
    private:
        int  _sockfd;
    public:
        //1.创建套结字
        bool Socket()
        {
            _sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
            if(_sockfd < 0)
            {
                perror("socket error");
                return false;
            }
        }

        //2.绑定地址信息
        bool Bind(std::string &ip,uint16_t port)
        {
            sockaddr_in  addr;
            addr.sin_family = AF_INET;
            addr.sin_port=htons(port);
            addr.sin_addr.s_addr=inet_addr(ip.c_str());
            socklen_t len = sizeof(sockaddr_in);

            int ret = bind(_sockfd,(sockaddr*)&addr,len);
            if(ret<0)
            {
                perror("bind error");    
            }
            return true;

        }

        //监听
        bool Listen(int backlog =5)
        {
            int ret = listen(_sockfd,backlog);
            if(ret < 0)
            {
                perror("Listen error");
                return false;
            }
            return true;
        }

        bool Connect(std::string &ip,uint16_t port)
        {
            sockaddr_in addr;
            addr.sin_family=AF_INET;
            addr.sin_port=htons(port);
            addr.sin_addr.s_addr=inet_addr(ip.c_str());
            socklen_t len = sizeof(sockaddr_in);
            int ret = connect(_sockfd,(sockaddr*)&addr,len);
            
            if (ret<0) {
                perror("connect error");
                return false;
            }
            return true;
        }

        bool Accept(TcpSocket *sock, std::string *ip=NULL,uint16_t *port = NULL)
        {
            int newfd;
            sockaddr_in addr;
            socklen_t len = sizeof(sockaddr_in);
            newfd = accept(_sockfd,(sockaddr*)&addr,&len);
            if(newfd <0)
            {
                perror("Accept error");
                return false;
            }
            sock->_sockfd = newfd;
            if(ip)
            {
                char *ptr = inet_ntoa(addr.sin_addr);
                ip->assign(ptr,strlen(ptr));
            }
            if(port)
            {
                *port = ntohs(addr.sin_port);
            }
            return true;
        }

        bool Send(char *buf,size_t len)
        {
            int ret;

            int slen = 0;
            while(slen < len)
            {
                ret = send(_sockfd,buf+slen,len-slen,0);
                if(ret < 0)
                {
                    return false;   
                }
                slen += ret;
            }
            return true;
        }

        bool Recv(char *buf,size_t *len = NULL)
        {
            int ret,rlen = 0;
            if(len)
            {
                while(rlen < *len)
                {
                    ret = recv(_sockfd,buf+rlen,*len-rlen,0);
                    if(ret < 0)
                    {
                        if(errno == EAGAIN || errno == EINTR)
                        {
                            continue;
                        }
                        return false;
                    }else if(ret == 0)
                    {
                        printf("peer shutdown conn!!\n");
                        return false;
                    }
                    rlen += ret;
                }
            }
            else
            {
                ret = recv(_sockfd,buf,1024,0);
                if(ret <= 0)
                {
                    return false;
                }
                if(len)
                {
                    *len = ret;
                }
            }
        }

        bool Close()
        {
            close(_sockfd);
            return true;
        }
};