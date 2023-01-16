#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include <err.h>
#include<sys/stat.h>
#include<sysexits.h>
int main(int argc,char *argv[]){
    
    int checking=mkdir(argv[1],0777);

    if(!checking){
        printf("Directory is created\n");
    }else{
        printf("Doesnot create directory\n");
    }
}