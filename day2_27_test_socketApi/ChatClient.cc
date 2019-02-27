#include "Socket.hpp"
#include<iostream>
#include"ChatClient.hpp"

void Usage(){
    std::cout<<"Usage: ip"<<std::endl;
}

int main(int argc,char *argv[])
{
    if (argc != 2) {
        Usage();
        exit(0);
    }
    
    std::string ip = argv[1];
    ChatClient *cp =new ChatClient(ip);
    cp->InitClient();
    bool flag = cp->ConnectServer();


    // int port = atoi(argv[2]);
    // int sock = SocketApi::Socket(SOCK_STREAM);
    // bool flag = SocketApi::Connect(sock,ip,port);

    if (flag) {
        std::cout<<"Connect success "<<std::endl;
    }

    return 0;
}