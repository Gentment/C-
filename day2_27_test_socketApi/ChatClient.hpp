#pragma ocne 
#include"Socket.hpp"

#define TCP_PORT 8080
#define UDP_PORT 8888

class ChatClient
{
private:
    std::string ip;
    int tcp_sock;
    int udp_sock;

public:
    ChatClient(std::string ip_):ip(ip_)
    {}

    void InitClient()
    {
        tcp_sock = SocketApi::Socket(SOCK_STREAM);
        udp_sock = SocketApi::Socket(SOCK_DGRAM);
    }

    bool ConnectServer()
    {
        return SocketApi::Connect(tcp_sock,ip,TCP_PORT);
    }

    // void Chat()
    // {

    // }
    ~ChatClient();
};