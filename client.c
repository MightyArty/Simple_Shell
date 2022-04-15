#include "shell.h"

int client()
{
    struct sockaddr_in add;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("error in connectiong...\n");
        return -1;
    }
    printf("success in creating socket\n");

    // do we need memset??
    add.sin_family = AF_INET;
    add.sin_port = 3000;
    add.sin_addr.s_addr = INADDR_ANY;

    int status = connect(sock, (struct sockaddr *)&add, sizeof(add));
    if (status == -1)
    {
        printf("Connection error...\n");
        return -1;
    }
    printf("connected to server on port: %d", add.sin_port);
    
    return 1;
}