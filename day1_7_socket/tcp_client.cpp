#include"tcp_socket.h"

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf("usage: ./tcp_client ip port\n");
        return -1;
    }

    std::string ip = argv[1];
    uint16_t port=atoi(argv[2]);
    TcpSocket sock;
    CHECK(sock.Socket());
    CHECK(sock.Connect(ip,port));
    
    while(1){
        char buff[1024];
        printf("client say:");
        fflush(stdout);
        scanf("%s",buff);
        memset(buff,0x00,1024);
        sock.Recv(buff);
        printf("server say :%s\n",buff);
    }
    sock.Close();
    
    return 0;
}
