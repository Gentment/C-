.PHONY:all
all:tcp_server tcp_client
tcp_server:tcp_server.cpp
	g++ -g $^ -o $@ -static
tcp_client:tcp_client.cpp
	g++ -g $^ -o $@ -static
.PHONY:clean
clean:
	rm tcp_client tcp_server