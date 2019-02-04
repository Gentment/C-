#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

void Usage()
{
	printf("Usage: ./server [ip] [port]\n");
}
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		Usage();
		return 1;
	}
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd < 0)
	{
		perror("socket error");
		return 1;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));

	int ret = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(ret < 0)
	{
		perror("bind error");
		return 1;
	}

	ret = listen(fd,5);
	if(ret<0)
	{
		perror("listen error");
		return 1;
	}

	while(1)
	{
		struct sockaddr_in client_addr;
		socklen_t len;
		int client_fd = accept(fd,(struct sockaddr*)&client_addr,&len);
		if(client_fd <0)
		{
			perror("accept");
			continue;
		}

		char input_buf[1024*10] = {0};
		ssize_t read_size = read(client_fd,input_buf,sizeof(input_buf)-1);
		char buf[1024] = {0};
		const char* hello = "<h1>hello world </h1>";
		sprintf(buf,"HTTP/1.0 200 ok\nContent-Length:%lu\n\n%s",strlen(hello),hello);
		write(client_fd,buf,strlen(buf));
	}
	return 0;
}
