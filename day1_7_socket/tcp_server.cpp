#include"tcp_socket.h"

int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printf("usage:./tcp_server ip port\n");
        return -1;
    }

    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    TcpSocket sock;
    CHECK(sock.Socket());
    CHECK(sock.Bind(ip,port));
    CHECK(sock.Listen());

    
    while(1){
        TcpSocket client;
        std::string ip;
        uint16_t port;
        if(sock.Accept(&client,&ip,&port)==false)
        {
            continue;
        }

        char buff[1024] ={0};
        client.Recv(buff);
        printf("client say:%s\n",buff);
        memset(buff,0x00,1024);
        printf("server say:");
        fflush(stdout);
        scanf("%s",buff);
        client.Send(buff,strlen(buff));
    }
    sock.Close();
    return 0;
}
