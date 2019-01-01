#include "tcpClient.h"

static void Usage(std::string proc)
{
	std::cout<<"Usage:"<<proc<<"Server_ip Server_port"<<std::endl;
}

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
			Usage(argv[0]);
			exit(1);
	}
	int port = atoi(argv[2]);
	std::string ip = argv[1];
	Client *cp = new Client(port,ip);

	cp->InitClient();
	cp->Connect();
	cp->Run();
	delete cp;
	return 0;
}
