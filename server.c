#include <unistd.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("succsessfully created TCP socket\n");

    // do we need memset??
    server_addr.sin_family = AF_INET;
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
            close(sock_client);
            // return the connection
            flag = 1;
        }
        else
        {
            for (int i = 0; i < BUFF_SIZE; i++)
            {
                printf("%c", buff[i]);
            }
            puts("");
        }
    }
    return 0;
}
