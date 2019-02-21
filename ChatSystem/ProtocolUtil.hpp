#pragma once
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string>
#include "Log.hpp"

class SocketApi
{
public:
	static int Socket(int type)
	{
		int fd = socket(AF_INET,type,0);
		if (fd < 0) {
			LOG("socket error",ERROR);
			exit(2);
		}
		return fd;
	}

	static int Bind(int sock,int port)
	{
		struct sockaddr_in local;
		local.sin_family = AF_INET;
		local.sin_addr.s_addr = htonl(INADDR_ANY);
		local.sin_port = htons(port);

		int n = bind(sock,(struct sockaddr*)&local ,sizeof(local));
		if (n < 0) {
			LOG("bind error",ERROR);
			exit(3);
		}
		
	}

	static int Listen(int sock,int listenMax)
	{
		if(listen(sock,listenMax) < 0)
		{
			LOG("listen error",ERROR);
			return -1;
		}
	}

	static bool Connect(const int &sock,std::string peer_ip,const int &port)
	{
		connect(sock,(struct sockaddr*)&peer_ip,port);
	}

	static void Accept(int sock,std::string peer_ip,const int &port)
	{
		socklen_t len = sizeof(peer_ip);
		int newfd = accept(sock,(struct sockaddr*)&peer_ip ,&len);
		if (newfd < 0) {
			return ;
		}		
	}

	~SocketApi();
	
};