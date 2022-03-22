#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void get_dir(){
    DIR *directory;
    struct dir *l_dir;
    directory = opendir(".");
    if (directory == NULL){
        printf("\n error in openning directory\n");
        return;
    }
    // while there are something to read
    while((l_dir = readdir(directory) != NULL)){
        
    }
}