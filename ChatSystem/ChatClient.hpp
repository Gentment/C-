#pragma once

#include <iostream>
#include <string>
#include "ProtocolUtil.hpp"

#define TCP_PROT 8080
#define UDP_PORT 8888
class ChatClient
{
public:
	
	ChatClient(std::string ip_):peer_ip(ip_)
	{
		
	}
	
	~ChatClient(){}

private:
	std::string peer_ip;
};