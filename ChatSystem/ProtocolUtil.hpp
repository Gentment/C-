#pragma once
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string>
#include "Log.hpp"
#include<json.h>
#include<sstream>

class Request
{
private:
	/* data */
public:
	std::string method;  // Register Login LogOut
	std::string content_length;
	std::string blank;
	std::string text;
public:
	Request():blank('\n'){}
};

class Utils
{
public:
	static bool RegisterEnter(std::string &nick_name,std::string school,std::string password)
	{
		std::cout<<"Please Input Nick Name:"<<std::endl;
		std::cin>> nick_name;
		std::cout<<"Please Input School:"<<std::endl;
		std::cin>>school;
		std::cout<<"Please Input password:"<<std::endl;
		std::cin>>password;
		std::string again;
		std::cout<<"Please Input password again:"<<std::endl;
		std::cin>>again;
		if(again == password)
		{

		}

	}

	static void  Seralize(Json::Value &root,std::string &outString)
	{
		Json::FastWriter write;
		outString = write.write(root);
	}
	static void UnSeralize(std::string &outString,Json::Value &root)
	{
		Json::Reader read;
		read.parse(outString,root,false);
	}


	static std::string IntToString(std::string &str)
	{
		std::stringstream ss;
		std::string s;
		ss>>s;
		return s;
	}

	static int StringToInt(std::string &str)
	{
		std::stringstream ss;
		int s;
		ss>>s;
		return s;
	}

	static void RecvOneLine(int sock,std::string)
	{

	}

	static void SendRequest(int sock,Request &rq)
	{

	}	

	static void RecvRequest(int sock,Request &rq)
	{
		RecvOneLine(sock,rq.method);
		RecvOneLine(sock,rq.content_length);
		RecvOneLine(sock,rq.bank);

		std::string &cl = rq.content_length;
		std::size_t pos = cl.find(": ");
		if(std::string::npos == pos)
		{
			return;			
		}
		std::string sub = cl.substr(pos+2);
		int size = StringToInt(sub);
		char c;
		for(auto i=0;i<size;i++){
			recv(sock,&c,1,0);
			(rq.text).push_back(c);
		}
	}

	static bool LoginEnter(unsigned int &id,std::string &outString)
	{
		std::cout<<"Please Enter Id:";
		std::cin>>id;
		std::cout<<"Please Enter Password";
		std::cin>>outString;
	}
};

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

	static int Accept(int sock,std::string peer_ip,const int &port)
	{
		socklen_t len = sizeof(peer_ip);
		int newfd = accept(sock,(struct sockaddr*)&peer_ip ,&len);
		if (newfd < 0) {

		}		
		return newfd;
	}

	static void Send(int sock,Request &rq)
	{	
		std::string &m_ = rq.method;
		std::string &cl_ = rq.content_length;
		std::string &b_ = rq.blank;
		std::string &pwd_ = rq.text;

		send(sock,m_.c_str(),sizeof(m_),true);
		send(sock,cl_.c_str(),sizeof(cl_),true);
		send(sock,b_.c_str(),sizeof(b_),true);
		send(sock,pwd_.c_str(),sizeof(pwd_),true);
	}

	~SocketApi();
	
};




