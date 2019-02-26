#pragma once 
#include "ProtocolUtil.hpp"
// #include "UserManager.hpp"
// #include "Message.hpp"
// #include "DataPool.hpp"

class ChatServer;
class Param
{
public:
    int sock;
    ChatServer *sp;
public:
    Param(ChatServer *sp_,int &sock_):
        sp(sp_),
        sock(sock_)
        {}
    ~Param(){}
};

class ChatServer
{
private:
    int tcp_listen_socket;
    int tcp_port;

    int udp_work_socket;
    int udp_port;

    // UserManager um;
    // DataPool pool;
public:
    ChatServer(int tcp_port_=8080,int udp_port_=8888):
        tcp_port(tcp_port_),
        tcp_listen_socket(-1),
        udp_port(udp_port_),
        udp_work_socket(-1)
    {}
    
    void InitServer()
    {
        tcp_listen_socket = SocketApi::Socket(SOCK_STREAM);
        udp_work_socket = SocketApi::Socket(SOCK_DGRAM);
        SocketApi::Bind(tcp_listen_socket,tcp_port);
        SocketApi::Bind(udp_work_socket,udp_port);
        SocketApi::Listen(tcp_listen_socket);
    }
    // unsigned int RegisterUser(const std::string name, const std::string school,const std::string passwd)
    // {
    //     return um.Insert(name,school,passwd);
    // }
    // unsigned int LoginUser(const unsigned int &id,const std::string &passwd,const std::string &ip,const std::string &port){
        
    //     return um.Check(id,passwd);
    // }

    // //product
    // void ProductMsg()
    // {
    //     std::string message;
    //     struct sockaddr_in peer;
    //     Utils::RecvMessage(udp_work_socket,message,peer);
    //     if(!message.empty()){
    //         pool.PutMessage(message);
    //         Message ms;
    //         ms.ToRecvValue(message);
    //         um.AddOnlineUser(ms.id,peer);
    //     }
    // }

    // //consume
    // void ConsumMsg()
    // {
    //     std::string message;
    //     pool.GetMessage(message);
    //     auto online = um.OnlineUser();
    //     for(auto it = online.begin; it < online.end; it++)
    //     {
    //         /* code */
    //     }
        
    // }

    //处理请求
    static void *HandlerRequest(void *arg)
    {
        Param *p = (Param*)arg;
        int sock = p->sock;
        ChatServer *sp = p->sp;
        delete p;

        pthread_detach(pthread_self());

        // Request rq;
        // Utils::RecvRequest(sock,rq);

        // Json::Value root;
        // Utils::UnSeralize(rq.text,root);
        // if(rq.method == "REGERIST")
        // {

        //     std::string name = root["name"].asString();
        //     std::string school = root["school"].asString();
        //     std::string passwd = root["password"].asString();

        //     unsigned int id = sp->RegisterUser(name,school,passwd);
        //     send(sock,&id,sizeof(id),0);
        // }else if(rq.method == "LOGIN"){
        //     unsigned int id = root["id"].asInt();
        //     std::string passwd = root["password"].asString();

        //     unsigned int result = sp->LoginUser(id,passwd);
        //     send(sock,&result,sizeof(result),0);
        // }else{

        // }

        close(sock);
    }

    void Start()
    {
        for(;;)
        {
            /* code */
            std::string ip;
            int port;
            std::cout<<"Accepting"<<std::endl;
            int sock = SocketApi::Accept(tcp_listen_socket,ip,port);
            if(sock > 0){
                std::cout<<"get a new client"<<ip<<":"<<port<<std::endl;

                Param *p = new Param(this,sock);
                pthread_t tid;
                pthread_create(&tid,NULL,HandlerRequest,p);
            }else{
               std::cout<<"Accept error"<<ip<<":"<<port<<std::endl;
 
            }

            std::cout<<"Accept end"<<std::endl;
        }

    }
    ~ChatServer();
};