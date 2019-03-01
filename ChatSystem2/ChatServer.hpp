#pragma once
#include "Socket.hpp"
#include "Request.hpp"
#include "Util.hpp"
#include "UserManager.hpp"
#include"Log.hpp"

class ChatServer;

class Pragma
{
public:
    int sock;
    ChatServer *sp;

    std::string ip;
    int port;
    Pragma(int sock_,ChatServer *sp_, std::string ip_,int p_):
        sock(sock_),
        sp(sp_),
        ip(ip_),
        port(p_)
    {}
};

class ChatServer
{
private:
    int tcp_listen_sock;
    int tcp_port;
    int udp_work_sock;
    int udp_port;

    UserManager um;
public:
    ChatServer(int tcp_port_=8080,int udp_port_=8888):
        tcp_port(tcp_port_),
        udp_port(udp_port_),
        tcp_listen_sock(-1),
        udp_work_sock(-1)
    {

    }

    /*create socket And bind socket And tcp_listen_sock listen*/
    void InitServer()
    {
        //create
        tcp_listen_sock = SocketApi::Socket(SOCK_STREAM);
        udp_work_sock = SocketApi::Socket(SOCK_DGRAM);
        //bind
        SocketApi::Bind(tcp_listen_sock,tcp_port);
        SocketApi::Bind(udp_work_sock,udp_port);
        //listen 
        SocketApi::Listen(tcp_listen_sock);
    }

    unsigned int  RegisterUser(std::string &name,std::string &school,std::string &passwd)
    {
        return um.Insert(name,school,passwd);
    }

    unsigned int LoginUser(unsigned int id,std::string &passwd,const std::string &ip,const unsigned int &port){
        unsigned int result = um.Check(id,passwd);
        if (result >= 10000) {
            /* code */
        // struct sockaddr_in peer;
        // peer.sin_addr.s_addr=inet_addr(ip);
        // um.AddOnlineuser(id,peer);
        }
        return result;
    }
    static void *HandlerRequest(void *arg)
    {
        Pragma *p = (Pragma*)arg;
        int sock = p->sock;
        ChatServer *cs = p->sp;
        std::string ip = p->ip;
        unsigned int port = p->port;
        delete p;
        pthread_detach(pthread_self());
        
        Request rq;
        SocketApi::RecvRequest(sock,rq);

        Json::Value root;
        LOG(rq.text,NORMAL);
        Util::UnSerializ(rq.text,root);

        std::cout<<"UnSerializ rq.text:"<<rq.text<<std::endl;

        if ("REGISTER" == rq.method) {
            std::string name = root["name"].asString();
            std::string school = root["school"].asString();
            std::string passwd = root["passwd"].asString();

            unsigned int id = cs->RegisterUser(name,school,passwd);
            
            std::cout<<"Register success returnd id:"<<id<<std::endl;       
            
            send(sock,&id,sizeof(id),0);        //???????
        }else if("LOGIN" == rq.method){
            unsigned int id = root["id"].asInt();
            std::string passwd = root["passwd"].asString();
            
            std::cout<<"LoginUser id:"<<id<<std::endl;

            unsigned int result = cs->LoginUser(id,passwd,ip,port);
            send(sock,&result,sizeof(result),0);    //?????
        }else {

        }
        close(sock);
    }
    void StartServer()
    {
        for(;;)
        {
            struct sockaddr_in cli_addr;
            std::string out_ip;
            int out_port;
            int sock = SocketApi::Accept(tcp_listen_sock,out_ip,out_port);
            if (sock > 0) {
                std::cout<<"Accept a new client"<<"ip:"<<out_ip<<"port:"<<out_port<<std::endl;
                
                Pragma *p = new Pragma(sock,this,out_ip,out_port);
                pthread_t tid;
                pthread_create(&tid,NULL,HandlerRequest,p);
            }
        }
    }
    ~ChatServer();
};