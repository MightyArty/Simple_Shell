#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h> 
#include <arpa/inet.h>

#define max_length 50



#define BUFF_SIZE 1024

char *IP = "localhost";
int PORT = 5500;
struct sockaddr_in add;
socklen_t addr_size;
char buff[BUFF_SIZE];

void client(){
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
    dup2(1,123);
    dup2(sock,1);
}



/**
 * @brief Check the current location
 * 
 * @param loc : current location
 */
void check_location(char *loc){
    if(getcwd(loc, max_length) == NULL){
        printf("error in finding the location, check again later...\n");

    }
}


/**
 * @brief Return the current directory
 * 
 */
void get_dir(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d){
        while((dir == readdir(d)) != NULL){
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    // if d == NULL
    else {
        printf("Error in reading directory!\n");
        return;
    }
}

int main(){
    char loc[max_length];   // for the location
    char com[max_length];   // for the command

    while(com != "EXIT"){
        check_location(loc);
        // printf("yes master?>$");
        printf("%s>$", loc);    // pritnf current location
        gets(com);  // read the command

        // return the string after ECHO command
        if(strncmp(com, "ECHO", 4) == 0){
            for(int i = 5 ; i < max_length && com[i] != '\0' ; i++){
                printf("%c", com[i]);
            }
            puts("\n");
            
        }

        // return list of files in the directory
        else if(strcmp(com, "DIR") == 0){
            get_dir();
        }

        else if(strcmp(com, "LOCAL") == 0){
            dup2(123,1);
        }
        // need to complete
        else if(strncmp(com, "TCP PORT", 8) == 0){
            client();
        }

        // if return 0 -> success
        // else -> error
        else if(strncmp(com, "CD", 3) == 0){
            // chdir is a system command
            if(chdir(&(com[3])) != 0){
                printf("error in changing directory...\n");
                return 1;
            }
        }
        // need to complete
        else if(strncmp(com, "COPY", 5) == 0){
            char src[max_length];
            char dest[max_length];
            int runner = 5;
            int i = 0;
            int j = 0;

            while(com[runner] != ' '){
                src[i++] = com[runner++]; 
            }
            src[i] = '\0';
        }

        else if(strncmp(com, "DELETE", 7) == 0){
            // our implemitation is using SYSTEM call
            unlink(&(com[7]));
        }

        // need to complete
        else{

            // system is a system call function
            // system(com);
            int situation = fork();
            if(situation == 0){
                char first[max_length] = "/bin/";

            }
            if(situation < 0){
                printf("error!\n");
                return 1;
            }
            wait();
        }
    }
    return 0;
}