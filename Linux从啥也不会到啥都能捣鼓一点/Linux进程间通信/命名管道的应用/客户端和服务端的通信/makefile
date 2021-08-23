.PHONY:all 
all: clientPipe serverPipe 
clientPipe:client.c
	gcc $^ -o $@
serverPipe:server.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -f clientPipe serverPipe
