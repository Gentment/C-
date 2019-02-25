#include<iostream>
#include "ChatServer.hpp"

#define TCP_PORT 8080
#define UDP_PORT 8888

void Usage()
{
    std::cout<<"Usage:"<<"tcp_port udp_port"<<std::endl;
}

void *RunProduct(void *arg)
{
    ChatServer *sp = (ChatServer*)arg;
    for(;;)
    {
        sp->ProductMsg();
    }
    
}
void *RunConsume(void *arg)
{
    ChatServer *sp = (ChatServer*)arg;
    for(;;)
    {   
        sp->ConsumMsg();
    }
        
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
    pthread_t c,p;
    pthread_create(&p,NULL,RunProduct,(void*)&sp);
    pthread_create(&c,NULL,RunConsume,(void*)&sp);
    sp->Start();
    
}