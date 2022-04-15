<<<<<<< HEAD
#include "shell.h"

int client()
{
    struct sockaddr_in add;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("error in connectiong...\n");
        return -1;
=======
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
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
    }
    printf("success in creating socket\n");

    // do we need memset??
    add.sin_family = AF_INET;
<<<<<<< HEAD
    add.sin_port = 3000;
    add.sin_addr.s_addr = INADDR_ANY;

    int status = connect(sock, (struct sockaddr *)&add, sizeof(add));
    if (status == -1)
    {
        printf("Connection error...\n");
        return status;
    }
    printf("connected to server on port: %d", add.sin_port);
    
    return 1;
=======
    add.sin_port = htons(9000);
    add.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sock_addr*)&add, sizeof(add));
    printf("connected to server on port: %d", PORT);
    // dup2(1,123);
    // dup2(sock,1);

    return 0;
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
}