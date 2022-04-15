#include <unistd.h>
#include <netinet/in.h>
<<<<<<< HEAD
#include <netinet/tcp.h>
=======
#include <netinet/tcp.h> 
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <dirent.h>
#define BUFF_SIZE 1024
int sock_server;
void sig_handler(int signum)
{
    switch (signum)
    {
    case SIGTSTP: // dad is dead
        printf("I'm the first signal..\n");
        close(sock_server);
    case SIGINT: // raise by user signal
        printf("I'm the second signal\n");
        close(sock_server);
    default:
        exit(1);
        close(sock_server);
    }
}
int main()
{
    signal(SIGTSTP, sig_handler);
    signal(SIGINT, sig_handler);
    struct sockaddr_in server_addr;

    char buff[BUFF_SIZE];
    sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_server < 0)
    {
        printf("error in connecting...\n");
        exit(1);
    }
=======

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

>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
    printf("succsessfully created TCP socket\n");

    // do we need memset??
    server_addr.sin_family = AF_INET;
<<<<<<< HEAD
    server_addr.sin_port = 3000;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int temp = bind(sock_server, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (temp < 0)
    {
        printf("error in bind\n");
        exit(1);
    }
    printf("bind successfully to port number: %d", server_addr.sin_port);

    listen(sock_server, 1);
    printf("listening...\n");
    int flag = 1;
    int sock_client;
    while (1)
    {
        if (flag)
        {
            sock_client = accept(sock_server, NULL, NULL);
            flag = 0;
        }
        bzero(buff, BUFF_SIZE);
        if (!recv(sock_client, buff, sizeof(buff), 0))
        {
=======
    server_addr.sin_port = htons(9000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

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
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
            close(sock_client);
            // return the connection
            flag = 1;
        }
<<<<<<< HEAD
        else
        {
            for (int i = 0; i < BUFF_SIZE; i++)
            {
                printf("%c", buff[i]);
            }
            puts("");
=======
        else{
            for(int i = 0 ; i < BUFF_SIZE ; i++){
                printf("%c", buff[i]);
            }
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
        }
    }
    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
