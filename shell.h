#define _CRT_SECURE_NO_WARNINGS
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
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define max_length 256
#define max_comm 1024
#define BUFF_SIZE 1024
char buff[BUFF_SIZE];
char *comArr[max_comm];
char loc[max_length]; // for the location
char com[max_length]; // for the command
int local_;
int sock;
void blue();
void green();
void purple();
void reset();

int run();
/**
 * @brief Check the current location
 *
 * @param loc : current location
 */
void check_location(char *loc);
/**
//  * @brief Return the current directory
//  *
//  */
void get_dir();
int _local();
/**
//  * @brief return the string after ECHO command
//  *
//  */
int _Echo();
int _TCP();
/**
//  * @brief return list of files in the directory
//  *
//  */
int _Dir();
int _cd();
int _copy();
int _Delete();
int Exit();
int client();
void systemCall();
int split(char *comm);
#ifndef __commands_H__
#define __commands_H__
typedef struct commands
{
    const char *comm;
    const int (*func_ptr)();
} commands;
#endif
void welcom();