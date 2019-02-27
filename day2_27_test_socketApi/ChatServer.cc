#include "Socket.hpp"
#include<iostream>
#include"ChatServer.hpp"

void Usage(){
    std::cout<<"Usage: ip port"<<std::endl;
    exit(1);
}

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        Usage();
    }
    int tcp_port = atoi(argv[1]);
    int udp_port = atoi(argv[2]);
    ChatServer *sp = new ChatServer(tcp_port,udp_port);
    sp->InitServer();
    sp->StartServer();

    // int port = atoi(argv[1]);
    // int sock = SocketApi::Socket(SOCK_STREAM);
    // SocketApi::Bind(sock,port);
    // SocketApi::Listen(sock);
    // std::string out_ip;
    // int out_port;
    // SocketApi::Accept(sock,out_ip,out_port);
    // std::cout<<"out_ip："<<out_ip<<"port："<<port<<std::endl;
    return 0;
}