<<<<<<< HEAD
#include "shell.h"
void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void blue()
{
    printf("\033[0;34m");
}
void green()
{
    printf("\033[0;32m");
}
void purple()
{
    printf("\033[0;35m");
}
void black()
{
    printf("\033[0;30m");
    printf("\033[47m");
}
void cyan()
{
    printf("\033[0;36m");
}
void backround()
{
    printf("\033[43m");
}
void reset()
{
    printf("\033[0m");
}
void welcom()
{
    char *logo[] = {"                     aRTI//BARK             ____\n",
                    "             simpleSH//////////Shl         |B//S|", "    |\n",
                    "          SH//////YS           shell//Sh   |A@@I|", "    | Welcome to simple shell\n",
                    " Sim aSystemSH//Sh              sys//B     |R$$M|", "    | Version 1.0\n",
                    " ArtABBBaraKk///Sh               sM//E     |A^^P|", "    |\n",
                    "         pCCCCY//h          eSS@@ y//E     |K**L|", "    | https://github.com/\n",
                    "         SPPPP///a          pP///AC//E     |&&&E|", "    |\n",
                    "              A//A            smP////S     |A**S|", "    | Have fun!\n",
                    "              p///Ac            sE///a     |R##H|", "    |\n",
                    "              P////YCpc           L//L     |T!!E|", "    | Wanna support simple shell?\n",
                    "       scccccp///pSP///p          p//l     |I%%L|", "    |\n",
                    "      sY/////////y  caa           S//h     |U--L|", "    |\n",
                    "       shsSellH//Ya              pY/Sh     |MIGT|", "    |\n",
                    "        sH/ShS////YCc          aC//Yp      |____|", "    |\n",
                    "         Si  shlll//SHsimpleSH//LSs\n",
                    "                  shell//////IPSHs\n",
                    "                       artium\n", '\0'};
    int i = 0;
    purple();
    printf("\n------------------------------------\033[1m Barak Sharabi && Artium Shabalin\033[0m------------------------------------\n\n");
    green();
    do
    {
        printf("%s", logo[i++]);
        if (i % 2 != 0 || i > 26)
            green();
        else
            blue();
    } while (logo[i]);
    reset();
    puts("\n\n");
}
=======
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



>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
/**
 * @brief Check the current location
 *
 * @param loc : current location
 */
void check_location(char *loc)
{
    if (getcwd(loc, max_length) == NULL)
    {
        printf("error in finding the location, check again later...\n");
    }
    else
    {
        printf("%d\n", local_);
        if (local_)
        {
            _local();
            printf("%s>", loc);
            blue();
            printf("$ ");
            dup2(1, 123);
            dup2(sock, 1);
            return;
        }
        printf("%s>", loc);
        blue();
        printf("$ ");
    }
}
<<<<<<< HEAD
=======


>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
/**
//  * @brief Return the current directory
//  *
//  */
void get_dir()
{

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("./")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        /* could not open directory */
        perror("");
        return;
    }
}
int _copy()
{
    char ch;
    FILE *source, *target;
    source = fopen(comArr[1], "r");
    if (source == NULL)
    {
        printf("Error...\n");
        return -1;
    }
    target = fopen(comArr[2], "w");
    if (target == NULL)
    {
        printf("Error...\n");
        fclose(source);
        return -1;
    }
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);

<<<<<<< HEAD
    printf("File copied successfully.\n");
    fclose(source);
    fclose(target);
    return 1;
}
void split(char *comm)
{
    char *token;
    /* get the first token */
    token = strtok(comm, " ");
    int i = 0;
    while (*(token + i))
    {
        *(token + i) = toupper(*(token + i));
        i++;
    }
    /* walk through other tokens */
    i = 0;
    while (token != NULL)
    {
        comArr[i++] = token;
        token = strtok(NULL, " ");
    }
    comArr[i] = NULL;
}
int _local()
{
    dup2(123, 1);
    local_ = 0;
    return 1;
}
int _Echo()
{
    int i = 0;
    while (comArr[++i] != NULL)
        printf("%s ", comArr[i]);
    puts("");
    return 1;
}
int _TCP()
{
    local_ = (strcmp(comArr[1], "PORT") == 0) ? client() : -1;
    if (local_)
    {
        dup2(1, 123);
        dup2(sock, 1);
    }
    return local_;
}
int _Dir()
{
    get_dir();
    return 1;
}
int _cd()
{
    if (chdir(comArr[1]) != 0)
    {
        printf("error in changing directory...\n");
        return -1;
    }
    return 1;
}
int _Delete()
{
    unlink(comArr[1]);
    return 1;
}
int Exit()
{
    return 0;
}
int run()
{
    int sys = 1;
    int ans = 1;
    while (ans)
    {
        sys = 1;
        green();
        check_location(loc);

        gets(com);
        split(com);
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
        {
            if (strcasecmp(comArr[0], commands[i].comm) == 0)
            {
                ans = commands[i].func_ptr();
                sys = 0;
            }
=======
int main(){
    char loc[max_length];   // for the location
    char com[max_length];   // for the command

    while(strcmp(com, "EXIT")){
        check_location(loc);
        // printf("yes master?>$");
        printf("%s>$", loc);    // pritnf current location
        gets(com);  // read the command

        // return the string after ECHO command
        if(strncmp(com, "ECHO", 4) == 0){
            for(int i = 5 ; i < max_length && com[i] != '\0' ; i++){
                printf("%c", com[i]);
            }
            puts("");
            
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
        else if(strncmp(com, "CD", 2) == 0){
            // chdir is a system command
            if(!(com[2])){
                printf(" ");
                continue;
            }
            strcpy(com, com+3);
            if(chdir((com)) != 0){
                printf("error in changing directory...\n");
                return 1;
            }
        }
        // need to complete
        else if(strncmp(com, "COPY", 4) == 0){
            char src[max_length];
            char dest[max_length];
            
        }

        else if(strncmp(com, "DELETE", 7) == 0){
            // our implemitation is using SYSTEM call
            unlink(&(com[7]));
        }

        // need to complete
        else{

            /**
             * system is a system call function
             */
            // system(com);

            
>>>>>>> cc8f9266960b2c56f15b78fdc47d9630e21667e6
        }
        /**
         * system is a system call function
         */
        if (sys)
            system(com);
    }
    return 1;
}
int main()
{
    welcom();
    return run();
}