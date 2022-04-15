FLAGS =-Wall -g
CC = gcc #if we want to change compiler


all: simpleShell server

simpleShell:main.o libclass.a 
	$(CC) $(FLAGS) -o simpleShell main.o libclass.a

main.o: main.c shell.h
	$(CC) $(FLAGS) -c main.c 

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
