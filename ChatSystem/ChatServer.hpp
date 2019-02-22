#pragma once 
#include "ProtocolUtil.hpp"
#include "UserManager.hpp"

class ChatServer
{
private:
    int tcp_work_socket;
    int udp_work_socket;
    int tcp_port;
    int udp_port;

    UserManager um;

public:
    ChatServer(int tcp_port_=8080,int udp_port_=8888):tcp_port(tcp_port_),udp_port(udp_port_)
    {}
    
    void InitServer()
    {
        tcp_work_socket = SocketApi::Socket(SOCK_STREAM);
        tcp_work_socket = SocketApi::Socket(SOCK_DGRAM);
    }

    
    static void *HandlerRequest(void *arg)
    {
        Param *p = (Pragma*)arg;
        int sock = p->sock;
        ChatServer *sp = p->sp;
        delete p;
        pthread_detach(pthread_self());

        Request rq;
        Utils::RecvRequest(sock,rq);
        if(rq.method == "REGERIST")
        {
            Json::Value root;
            Utils::Seralize(root,rq.text);


        }
    }

    void Start()
    {
        pthread_t tid;
        pthread_create(&tid,NULL,HandlerRequest,);

    }
    ~ChatServer();
};