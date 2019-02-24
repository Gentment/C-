cc=g++
server=ChatServer
client=ChatClient

.PHONY:(server)(client)
server:
	(cc) -o -std=c++11 $@ $^
client:
	(cc) -o $@ $^
.PHONY clean
clean:
	rm server client