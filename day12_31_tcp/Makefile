.PHONY:all
all:tcpClient tcpServer

tcpClient:tcpClient.cpp
	g++ -o $@ $^ -static
tcpServer:tcpServer.cpp
	g++ -o $@ $^ -static -lpthread
.PHONY:clean
clean:
	rm tcpClient tcpServer
