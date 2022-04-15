FLAGS =-Wall -g
CC = gcc #if we want to change compiler


all: simpleShell server

simpleShell:shell.o libclass.a 
	$(CC) $(FLAGS) -o simpleShell shell.o libclass.a

shell.o: shell.c shell.h
	$(CC) $(FLAGS) -c shell.c 

libclass.a:client.o
	ar -rcs libclass.a client.o


client.o: client.c shell.h
	$(CC) $(FLAGS) -c client.c 	


server: server.o
	$(CC) $(FLAGS) -o server server.o 	

server.o:
	$(CC) $(FLAGS) -c server.c 

.PHONY: clean
clean:
	rm -f *.o *.a *.so simpleShell server

cmd:
	./simpleShell 

run:
	./server
