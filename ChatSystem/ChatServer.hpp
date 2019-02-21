#pragma once 
#include "ProtocolUtil.hpp"

class ChatServer
{
private:
    int tcp_work_socket;
    int udp_work_socket;
    int tcp_port;
    int udp_port;

public:
    ChatServer(int tcp_port_=8080,int udp_port_=8888):tcp_port(tcp_port_),udp_port(udp_port_){}
    
    void InitServer()
    {
        tcp_work_socket = SocketApi::Socket(SOCK_STREAM);
        tcp_work_socket = SocketApi::Socket(SOCK_DGRAM);
    }

    void Start()
    {
        
    }
    ~ChatServer();
};