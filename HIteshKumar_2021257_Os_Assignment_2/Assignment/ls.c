#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include <err.h>
#include<sys/stat.h>
#include<sysexits.h>
int main(int argc,char *argv[]){
    
    struct dirent *de;
    DIR *dr = opendir(".");
    if(strcmp(argv[1],"~")==0){
        
        struct dirent *de;
        DIR *dr = opendir("/home/hitesh");
        if (dr == NULL)  
        {
            printf("Does not open the current directory!!!" );
            return 0;
        }
 
        while ((de = readdir(dr)) != NULL){
            if(strcmp(de->d_name,"..")!=0 && strcmp(de->d_name,".")!=0 &&de->d_name[0]!='.'){
                printf("%s ", de->d_name);
            }
        }
        printf("\n");
    }
    else if(strcmp(argv[1],"-a")==0){
        DIR *dr = opendir(".");
        if (dr == NULL)  
        {
            printf("Does not open the current directory!!!" );
            return 0;
        }

        
        while ((de = readdir(dr)) != NULL){
            if(strcmp(de->d_name,"..")!=0 && strcmp(de->d_name,".")!=0){
                printf("%s ", de->d_name);
            }
        }
        printf("\n");
    }
    else{
        
                
    }


    closedir(dr); 
}