#include<iostream>
#include "ChatServer.hpp"
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
    int tcp_port = htons();
    int udp_port = htons();
    ChatServer *sp = new ChatServer(tcp_port,udp_port);
    sp->InitServer();
    sp->Start();
    
}