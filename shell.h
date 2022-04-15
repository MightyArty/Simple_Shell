#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define max_length 256
#define max_comm 1024
#define BUFF_SIZE 1024
char buff[BUFF_SIZE];
char *comArr[max_comm];
char loc[max_length]; // for the location
char com[max_length]; // for the command
int local_;
int sock;
void red();
void yellow();
void blue();
void green();
void purple();
void black();
void cyan();
void backround();
void reset();
int run();
void check_location(char *loc);
void get_dir();
int _local();
int _Echo();
int _TCP();
int _Dir();
int _cd();
int _copy();
int _Delete();
int Exit();
int client();
void split(char *comm);
static struct commands
{
    const char *comm;
    const int (*func_ptr)();
} commands[] = {
    {"ECHO", _Echo},
    {"DIR", _Dir},
    {"LOCAL", _local},
    {"DELETE", _Delete},
    {"CD", _cd},
    {"TCP", _TCP},
    {"COPY", _copy},
    {"EXIT", Exit},
};
void welcom();