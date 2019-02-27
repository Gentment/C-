#include "ProtocolUtil.hpp"
#include<string>
#define PORT 8080

int main(int argc,char *argv[])
{
    if(argc != 2){
        std::cout<<"Usage :input ip"<<std::endl;
        exit(0);
    }

    std::string ip = argv[1];
    
    int sock = SocketApi::Socket(SOCK_STREAM);
    bool flag = SocketApi::Connect(sock,ip,PORT);
    if (flag) {
        std::cout<<"Connect success"<<std::endl;
    }
    return 0;
}