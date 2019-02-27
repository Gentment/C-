#pragma once

#include <iostream>
#include <string>
// #include<json.h>
#include "ProtocolUtil.hpp"
// #include "UserManager.hpp"
// #include "Message.hpp"

#define TCP_PROT 8080
#define UDP_PORT 8888
class ChatClient
{
private:
	std::string peer_ip;
	int tcp_sock;
	int udp_sock;

	unsigned id;
	std::string nick_name;
    std::string school;
    std::string password;
public:
	
	ChatClient(std::string ip_):peer_ip(ip_)
	{
		// id = 0;
		// tcp_sock = -1;
		// udp_sock = -1;
	}
	void InitClient()
	{
		tcp_sock = SocketApi::Socket(SOCK_STREAM);
		udp_sock = SocketApi::Socket(SOCK_DGRAM);
	}
	bool ConnectServer()
	{
		//客户端连接服务器
		std::cout<<"Connecting..."<<std::endl;
		return SocketApi::Connect(tcp_sock,peer_ip,TCP_PROT);
	}

	// bool Register()
	// {
	// 	if(Utils::RegisterEnter(nick_name,school,password) && ConnectServer())
	// 	{
	// 		Request rq;
	// 		rq.method = "REGISTER\n";

	// 		Json::Value root;
	// 		root["nick"] = nick_name;
	// 		root["school"] = school;
	// 		root["password"] = password;

	// 		Utils::Seralize(root,rq.text);
			
	// 		rq.content_length = "Content-Length: "+ Utils::IntToString(rq.text).size()+'\n';

	// 		Utils::SendRequest(tcp_sock,rq);
	// 		recv(tcp_sock,&id,sizeof(id),0);
	// 		bool res = false;
	// 		if(id >= 10000)
	// 		{
	// 			std::cout<<"Register Success! Your Login ID is: "<<id<<std::endl;
	// 			res = true;
	// 		}else{
	// 			std::cout<<"Register Failed ! Code is :"<<id<<std::endl;
	// 		}
	// 		close(tcp_sock);
	// 		return res;
	// 	}
	// }

	// bool Login()
	// {
	// 	if(Utils::LoginEnter(id,password) && ConnectServer())
	// 	{
	// 		Request rq;
	// 		rq.method = "LOGIN\n";

	// 		Json::Value root;
	// 		root["id"] = id;
	// 		root["password"] = password;

	// 		Utils::Seralize(root,rq.text);
			
	// 		rq.content_length = "Content-Length: "+ Utils::IntToString(rq.text).size()+'\n';

	// 		Utils::SendRequest(tcp_sock,rq);
	// 		int result = recv(tcp_sock,&id,sizeof(id),0);
	// 		bool res = false;
	// 		if(result >= 10000)
	// 		{
	// 			std::cout<<"Login Success! "<<std::endl;
	// 			res = true;
	// 		}else{
	// 			std::cout<<"Login Failed ! Code is :"<<result<<std::endl;
	// 		}
	// 		close(tcp_sock);
	// 		return res;
	// 	}
	// }

	void Chat()
	{
		// Message msg;
		while(1){
			/* code */
			std::cout<<"Connect Success!"<<std::endl;
		}
		
	}
	~ChatClient(){}
};