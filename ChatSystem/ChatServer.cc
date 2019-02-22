#include<iostream>
#include "ChatServer.hpp"

#define TCP_PORT 8080
#define UDP_PORT 8888

void Usage()
{
    std::cout<<"Usage:"<<"tcp_port udp_port"<<std::endl;
}
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        Usage();

        exit(1);
    }
    int tcp_port = htons(TCP_PORT);
    int udp_port = htons(UDP_PORT);
    ChatServer *sp = new ChatServer(tcp_port,udp_port);
    sp->InitServer();
    sp->Start();
    
}