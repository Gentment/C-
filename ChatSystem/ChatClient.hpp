#pragma once

#include <iostream>
#include <string>
#include<json.h>
#include "ProtocolUtil.hpp"
#include "UserManager.hpp"

#define TCP_PROT 8080
#define UDP_PORT 8888
class ChatClient
{
public:
	
	ChatClient(std::string ip_):peer_ip(ip_)
	{
	
		id = 0;
		tcp_sock = -1;
		udp_sock = -1;
	}
	void InitClient()
	{
		tcp_sock = SocketApi::Socket(SOCK_STREAM);
		udp_sock = SocketApi::Socket(SOCK_DGRAM);
	}
	bool ConnectServer()
	{
		return SocketApi::Connect(tcp_sock,peer_ip,TCP_PROT);
	}

	void Register()
	{
		if(Utils::RegisterEnter(nick_name,school,password) && ConnectServer())
		{
			Request rq;
			rq.method = "REGISTER\n";

			Json::Value root;
			root["nick"] = nick_name;
			root["school"] = school;
			root["password"] = password;

			Utils::Seralize(root,rq.text);
			
			rq.content_length = "Content-Length: "+ Utils::IntToString(rq.text)+'\n';

			SocketApi::Send(tcp_sock,rq);
		}
	}

	bool Login()
	{

	}

	void Chat()
	{

	}
	~ChatClient(){}

private:
	std::string peer_ip;
	int tcp_sock;
	int udp_sock;

	unsigned id;
	std::string nick_name;
    std::string school;
    std::string password;
};