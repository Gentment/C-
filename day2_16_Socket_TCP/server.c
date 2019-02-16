#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>

#define SERVE_IP "127.0.0.1"
#define SERVE_PORT 8888
int main()
{
    int lfd,cfd;
    struct sockaddr_in serv_addr,clie_addr;
    socklen_t clie_addr_len;
    char buf[BUFSIZ],clie_IP[BUFSIZ];
    int n,i;

    lfd = socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVE_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(lfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(lfd,10);

    clie_addr_len = sizeof(clie_addr);
    while(1){
        printf("Client IP:%s,port:%dd\n",inet_ntop(AF_INET,&clie_addr.sin_addr.s_addr,clie_IP,sizeof(clie_IP)),ntohs(clie_addr.sin_port));
        n = read(cfd,buf,sizeof(buf));
        for(int i=0;i<n;++i)
        {
            buf[i] = toupper(buf[i]);
            write(cfd,buf,n);
        }
    }
    close(lfd);
    close(cfd);
    
    return 0;
}