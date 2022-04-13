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
struct sockaddr_in add;
socklen_t addr_size;
char buff[BUFF_SIZE];

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        printf("error in connectiong...\n");
        exit(1);
    }
    printf("success in creating socket\n");

    // do we need memset??
    add.sin_family = AF_INET;
    add.sin_port = htons(9000);
    add.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sock_addr*)&add, sizeof(add));
    printf("connected to server on port: %d", PORT);
    // dup2(1,123);
    // dup2(sock,1);

    return 0;
}