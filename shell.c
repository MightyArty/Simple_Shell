#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define max_length 50

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

}

int main(){
    char loc[max_length];   // for the location
    char com[max_length];   // for the command

    while(com != "EXIT"){
        check_location(loc);
        // printf("yes master?>$");
        printf("%s>$", loc);    // pritnf current location
        gets(com);  // read the command

        if(strncmp(com, "ECHO", 5) == 0){
            for(int i = 5 ; i < max_length && com[i] != '\0' ; i++){
                printf("%c\n", com[i]);
            }
        }

        else if(strcmp(com, "DIR") == 0){
            get_dir();
        }

        else if(strcmp(com, "LOCAL") == 0){

        }
        // need to complete
        else if(strncmp(com, "TCP PORT", 8) == 0){

        }

        else if(strncmp(com, "CD", 3) == 0){
            // chdir is a system command
            if(chdir(&(com[3])) != 0){
                printf("error in accessing the directory...\n");
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