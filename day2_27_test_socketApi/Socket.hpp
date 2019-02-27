#pragma once
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string>
#include<sys/socket.h>
#include "Log.hpp"

#define BACKLOG 5

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

	static int Listen(int sock)
	{
		if(listen(sock,BACKLOG) < 0)
		{
			LOG("listen error",ERROR);
			exit(4);
		}
	}

	static bool Connect(const int &sock,std::string peer_ip,const int &port)
	{
		struct sockaddr_in cli_addr;
		cli_addr.sin_family =AF_INET;
		cli_addr.sin_addr.s_addr = inet_addr(peer_ip.c_str());
		cli_addr.sin_port = htons(port);
		if(connect(sock,(struct sockaddr*)&cli_addr,sizeof(cli_addr))<0){
			perror("connect error:");
			LOG("connect error",WARNING);
			return false;
		}
		return true;
	}

	static int Accept(int sock,std::string &out_ip,int &out_port)
	{
		struct sockaddr_in peer;

		socklen_t len = sizeof(peer);
		int fd = accept(sock,(struct sockaddr*)&peer ,&len);  //返回一个socket套结字
		if (fd < 0) {
			LOG("listen error",WARNING);
			return -1;
		} 
		out_ip = inet_ntoa(peer.sin_addr);
		out_port = htons(peer.sin_port);		
		return fd;
	}
};