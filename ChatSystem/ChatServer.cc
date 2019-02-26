#include<iostream>
#include "ChatServer.hpp"

void Usage(char *argv)
{
    std::cout<<"Usage:"<<"tcp_port udp_port"<<std::endl;
}

// void *RunProduct(void *arg)
// {
//     ChatServer *sp = (ChatServer*)arg;
//     for(;;)
//     {
//         sp->ProductMsg();
//     }
    
// }
// void *RunConsume(void *arg)
// {
//     ChatServer *sp = (ChatServer*)arg;
//     for(;;)
//     {   
//         sp->ConsumMsg();
//     }
        
// }
// ./ChatServer tcp_port udp_port
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    int tcp_port = atoi(argv[0]);
    int udp_port = atoi(argv[1]);
    ChatServer *sp = new ChatServer(tcp_port,udp_port);
    sp->InitServer();
    // pthread_t c,p;
    // pthread_create(&p,NULL,RunProduct,(void*)&sp);
    // pthread_create(&c,NULL,RunConsume,(void*)&sp);
    sp->Start();
    
}