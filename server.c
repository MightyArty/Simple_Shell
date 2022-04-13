#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h> 
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

char *IP = "localhost";
int PORT = 5500;
int sock_server;
int sock_client;

char buff[BUFF_SIZE];

struct sockaddr_in server_addr, client_addr;
socklen_t addr_size;

int main(){
    sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_server < 0){
        printf("error in connecting...\n");
        exit(1);
    }

    printf("succsessfully created TCP socket\n");

    // do we need memset??
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(IP);

    int temp = bind(sock_server, (struct sock_addr*)&server_addr, sizeof(server_addr));
    if(temp < 0){
        printf("error in bind\n");
        exit(1);
    }
    printf("bind successfully to port number: %d", PORT);

    listen(sock_server,1);
    printf("listening...\n");
    int flag = 1;
    while(1){
        if(flag){
        addr_size = sizeof(client_addr);
        sock_client = accept(sock_server, (struct sock_addr*)&client_addr, &addr_size);
        flag = 0;
        printf("client is connected on port number: %d", PORT);
        }
        bzero(buff, BUFF_SIZE);
        if(!recv(sock_client, buff, sizeof(buff), 0)){
            close(sock_client);
            // return the connection
            flag = 1;
        }
        else{
            for(int i = 0 ; i < BUFF_SIZE ; i++){
                printf("%c", buff[i]);
            }
        }
    }
    return 0;
}

