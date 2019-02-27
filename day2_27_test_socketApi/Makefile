
.PHONY:all
server=ChatServer
client=ChatClient

all:$(server) $(client)
$(server):ChatServer.cc
	g++ -o $@ $^ -static
$(client):ChatClient.cc
	g++ -o $@ $^ -static
.PHONY:clean
clean:
	rm -f $(server) $(client)