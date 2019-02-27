#pragma once
#include "Socket.hpp"
#include "Request.hpp"

class ChatServer;

class Pragma
{
public:
    int sock;
    ChatServer *sp;
    Pragma(int sock_,ChatServer *sp_):sock(sock_),sp(sp_)
    {}
};

class ChatServer
{
private:
    int tcp_listen_sock;
    int tcp_port;
    int udp_work_sock;
    int udp_port;
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

    static void *HandlerRequest(void *arg)
    {
        Pragma *p = (Pragma*)arg;
        int sock = p->sock;
        ChatServer *cs = p->sp;
        delete p;
        pthread_detach(pthread_self());
        
        Request rq;
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
                
                // Pragma *p = new Pragma(sock,this);
                // pthread_t tid;
                // pthread_create(&tid,NULL,HandlerRequest,p);
            }
        }
    }
    ~ChatServer();
};