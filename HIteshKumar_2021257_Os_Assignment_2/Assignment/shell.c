#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>

void white(){
    printf("\033[0;37m");
}
void cyan(){
    printf("\033[0;36m");
}
void printinfo(){
    yellow();
    printf("--------------------------------------------------");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    red();
    printf("|          Welcome to Hitesh's Shell              |");
    yellow();
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("|                                                 |");
    printf("\n");
    printf("--------------------------------------------------\n");
    cyan();


}

void * exec(void * str) {
    char * call = (char *)str;
    system(call);
    return NULL;
}

void red () {
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}
void black(){
    printf("\033[0;30m");
}


int main(){
    printinfo();
    
    int maxlenght=100;
    char path[100];
    getcwd(path,100);
    printf("%s\n",path);
    
    char *home=getenv("HOME");

    
    while(2){
        char line[100];
        printf(">>> ");
        fgets(line,100,stdin);
        //printf("%s",line);
        if(strcmp(line,"exit\n")==0){
            break;
        }
        if(strcmp(line,"\n")==0){
            continue;
        }
        char input[20][20];
        char *token=strtok(line," \n");
        int total_no_of_words=0;
        while(token != NULL ) {
            for(int j=0;j<strlen(token);j++){
                input[total_no_of_words][j]=token[j];
            }
            input[total_no_of_words][strlen(token)]='\0';
            token=strtok(NULL," \n");
            total_no_of_words++;
        }
        if (strcmp(input[total_no_of_words-1],"&t")==0) {
            if(strcmp(input[0],"ls")==0){
                if(strcmp(input[1],"~")==0){
                    pid_t pid=fork();
                    if(pid==0){
                        execl("/home/hitesh/Desktop/Assignment/ls","/home/hitesh/Desktop/Assignment/ls",input[1],NULL,NULL);
                    }else if(pid>0){
                        wait(NULL);
                    }else{
                        printf("Fork is failed");
                    }
                }else if(strcmp(input[1],"-a")==0){
                    pthread_t thread;
                    int a;
                    char strrr[20]="./ls ";
                    if (total_no_of_words>2) {
                        strcat(strrr,input[1]);
                    }
                    a = pthread_create(&thread,NULL,exec,strrr);
                    a = pthread_join(thread,NULL);
                }
                else{
                    struct dirent *de;
                    DIR *dr = opendir(".");
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
    
            }else if(strcmp(input[0],"mkdir")==0){
                if(strcmp(input[1],"-v")==0){
                    if(total_no_of_words==3){
                        printf("Error in this command\n");
                    }else{
                        for(int i=2;i<total_no_of_words-1;i++){
                            pthread_t thread;
                            int a;
                            char strrr[20]="./mkdir ";
                            if (total_no_of_words>2) {
                                strcat(strrr,input[i]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);
                        }
                    }
                    
                }
                // else if(strcmp(input[1],"-p")){
                //     if(total_no_of_words==2){
                //         printf("Error in this command\n");
                //     }else if(total_no_of_words==3){
                //         pid_t pid=fork();
                //         if(pid==0){
                //             execl("/home/hitesh/Desktop/Assignment/mkdir","/home/hitesh/Desktop/Assignment/mkdir",input[2],NULL,NULL);
                //         }else if(pid>0){
                //             wait(NULL);
                //         }else{
                //             printf("Fork is failed");
                //         }
                //     }else{
                //         printf("Error in this command\n");
                //     }

                // }
                else{
                    if(total_no_of_words==3){
                        pthread_t thread;
                        int a;
                        char strrr[20]="./mkdir ";
                        strcat(strrr,input[1]);
                        a = pthread_create(&thread,NULL,exec,strrr);
                        a = pthread_join(thread,NULL);
                    }else{
                        printf("Error in this command\n");
                        
                    }
                }
            }else if(strcmp(input[0],"cat")==0){
                if(total_no_of_words==1){
                    printf("Error in this command");

                }else{
                    if(strcmp(input[1],"-n")==0){
                        for(int i=2;i<total_no_of_words-1;i++){
                            pthread_t thread;
                            int a;
                            char strrr[20]="./cat ";
                            strcat(strrr,"-n ");
                            if (total_no_of_words>2) {
                                strcat(strrr,input[i]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);
                        }


                    }
                    else if(strcmp(input[1],"-E")==0){
                        pthread_t thread;
                            int a;
                            char strrr[20]="./cat ";
                            strcat(strrr,"-E ");
                            if (total_no_of_words>2) {
                                strcat(strrr,input[2]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);

                    }
                    else{
                        for(int i=1;i<total_no_of_words-1;i++){
                            pthread_t thread;
                            int a;
                            char strrr[20]="./cat ";
                            if (total_no_of_words>2) {
                                strcat(strrr,input[i]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);
                        }
                }
                }
            }else if(strcmp(input[0],"rm")==0){
                if(total_no_of_words==1){
                    printf("Error in this command");
                }else{
                    if(strcmp(input[1],"-i")==0){
                        for(int i=2;i<total_no_of_words-1;i++){
                            pthread_t thread;
                            int a;
                            char strrr[20]="./rm ";
                            if (total_no_of_words>2) {
                                strcat(strrr,input[i]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);
                        } 
                    }
                    else{
                        for(int i=1;i<total_no_of_words-1;i++){
                            pthread_t thread;
                            int a;
                            char strrr[20]="./rm ";
                            if (total_no_of_words>2) {
                                strcat(strrr,input[i]);
                            }
                            a = pthread_create(&thread,NULL,exec,strrr);
                            a = pthread_join(thread,NULL);
                            
                            } 
                    }
                }
            }else if(strcmp(input[0],"date")==0){
                if(total_no_of_words==2){
                    time_t Time;
                    struct tm *tm;
                    time(&Time);
                    tm=localtime(&Time);
                    char buffer[100];
                    strftime(buffer,100,"%a %b %d %X %Z %Y ", tm);
                    printf("%s\n", buffer);
                }else{
                    pthread_t thread;
                    int a;
                    char strrr[20]="./date ";
                    if (total_no_of_words>2) {
                        strcat(strrr,input[1]);
                    }
                    a = pthread_create(&thread,NULL,exec,strrr);
                    a = pthread_join(thread,NULL);
                }
            }
        }

        else {
            if(strcmp(input[0],"pwd")==0){
                if(total_no_of_words==1){
                    char hitesh[100];
                    getcwd(hitesh,100);
                    printf("%s\n",hitesh);
                }else if(total_no_of_words==2){

                    if(strcmp(input[1],"-P")==0){


                        char hitesh[100];
                        getcwd(hitesh,100);
                        printf("%s\n",hitesh);
                    }else if(strcmp(input[1],"-L")==0){

                        char hitesh[100];
                        getcwd(hitesh,100);
                        printf("%s\n",hitesh);
                    }else{
                        printf("Error in this command\n");
                    }
                }
                else{
                    printf("Error in this command\n");
                }

            }
            else if(strcmp(input[0],"cd")==0){
                if(total_no_of_words==1){
                    chdir(home);
                }else if(total_no_of_words==2){
                    if(chdir(input[1])==0){
                        continue;
                    }else if(strcmp(input[1],"~")==0){
                        chdir(home);
                    }
                    
                    else{
                        printf("Error in this command\n");
                    }
                }
            }
            else if(strcmp(input[0],"echo")==0){
                if(strcmp(input[1],"-n")==0){
                    for(int i=2;i<total_no_of_words;i++){
                    if(i==total_no_of_words-1 && input[i][strlen(input[i])-1]=='\"'){
                        input[i][strlen(input[i])-1]='\0';
                        
                    }
                    if(i==2&& input[i][0]=='\"'){
                        printf("%s ",input[i]+1);

                    }
                    
                    else {
                        printf("%s ",input[i]);
                    }
                }
                }else if(strcmp(input[1],"*")==0){
                    struct dirent *de;
    
        
                    DIR *dr = opendir(".");
                
                    if (dr == NULL)  
                    {
                        printf("Does not open the current directory!!!" );
                        return 0;
                    }
                
                    
                    while ((de = readdir(dr)) != NULL)
                            printf("%s ", de->d_name);
                
                    closedir(dr); 


                }
                else{
                    for(int i=1;i<total_no_of_words;i++){
                    if(i==total_no_of_words-1 && input[i][strlen(input[i])-1]=='\"'){
                        input[i][strlen(input[i])-1]='\0';
                        
                    }
                    if(i==1&& input[i][0]=='\"'){
                        printf("%s ",input[i]+1);

                    }
                    
                    else {
                        printf("%s ",input[i]);
                    }
                }
                printf("\n");
            }
            }
            else if(strcmp(input[0],"ls")==0){
                if(strcmp(input[1],"~")==0){
                    pid_t pid=fork();
                    if(pid==0){
                        execl("/home/hitesh/Desktop/Assignment/ls","/home/hitesh/Desktop/Assignment/ls",input[1],NULL,NULL);
                    }else if(pid>0){
                        wait(NULL);
                    }else{
                        printf("Fork is failed");
                    }
                }else if(strcmp(input[1],"-a")==0){
                    pid_t pid=fork();
                    if(pid==0){
                        execl("/home/hitesh/Desktop/Assignment/ls","/home/hitesh/Desktop/Assignment/ls",input[1],NULL,NULL);
                    }else if(pid>0){
                        wait(NULL);
                    }else{
                        printf("Fork is failed");
                    }
                }
                else{
                    struct dirent *de;
                    DIR *dr = opendir(".");
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
    
            }else if(strcmp(input[0],"mkdir")==0){
                if(strcmp(input[1],"-v")==0){
                    if(total_no_of_words==2){
                        printf("Error in this command\n");
                    }else{
                        for(int i=2;i<total_no_of_words;i++){
                            pid_t pid=fork();
                            if(pid==0){
                                execl("/home/hitesh/Desktop/Assignment/mkdir","/home/hitesh/Desktop/Assignment/mkdir",input[i],NULL,NULL);
                            }else if(pid>0){
                                wait(NULL);
                            }else{
                                printf("Fork is failed");
                            }
                        }
                    }
                    
                }
                // else if(strcmp(input[1],"-p")){
                //     if(total_no_of_words==2){
                //         printf("Error in this command\n");
                //     }else if(total_no_of_words==3){
                //         pid_t pid=fork();
                //         if(pid==0){
                //             execl("/home/hitesh/Desktop/Assignment/mkdir","/home/hitesh/Desktop/Assignment/mkdir",input[2],NULL,NULL);
                //         }else if(pid>0){
                //             wait(NULL);
                //         }else{
                //             printf("Fork is failed");
                //         }
                //     }else{
                //         printf("Error in this command\n");
                //     }

                // }
                else{
                    if(total_no_of_words==2){
                        pid_t pid=fork();
                        if(pid==0){
                            execl("/home/hitesh/Desktop/Assignment/mkdir","/home/hitesh/Desktop/Assignment/mkdir",input[1],NULL,NULL);
                        }else if(pid>0){
                            wait(NULL);
                        }else{
                            printf("Fork is failed");
                        }
                    }else{
                        printf("Error in this command\n");
                        
                    }
                }
            }else if(strcmp(input[0],"cat")==0){
                if(total_no_of_words==1){
                    printf("Error in this command");

                }else{
                    if(strcmp(input[1],"-n")==0){
                        for(int i=2;i<total_no_of_words;i++){
                            pid_t pid=fork();
                            if(pid==0){
                                execl("/home/hitesh/Desktop/Assignment/cat","","-n",input[i],NULL,NULL);
                            }else if(pid>0){
                                wait(NULL);
                            }else{
                                printf("Fork is failed");
                            }
                        }


                    }else if(strcmp(input[1],"-E")==0){
                        pid_t pid=fork();
                        if(pid==0){
                            execl("/home/hitesh/Desktop/Assignment/cat","","-E",input[2],NULL,NULL);
                        }else if(pid>0){
                            wait(NULL);
                        }else{
                            printf("Fork is failed");
                        }
                    }
                    else{
                        for(int i=1;i<total_no_of_words;i++){
                            pid_t pid=fork();
                            if(pid==0){
                                execl("/home/hitesh/Desktop/Assignment/cat","",input[i],NULL,NULL);
                            }else if(pid>0){
                                wait(NULL);
                            }else{
                                printf("Fork is failed");
                            }
                        }
                }
                }
            }else if(strcmp(input[0],"rm")==0){
                if(total_no_of_words==1){
                    printf("Error in this command");
                }else{
                    if(strcmp(input[1],"-i")==0){
                        for(int i=2;i<total_no_of_words;i++){
                            pid_t pid=fork();
                            if(pid==0){
                                execl("/home/hitesh/Desktop/Assignment/rm","","-i",input[i],NULL,NULL);
                            }else if(pid>0){
                                wait(NULL);
                            }else{
                                printf("Fork is failed");
                            }
                        } 
                    }
                    else{
                        for(int i=1;i<total_no_of_words;i++){
                            pid_t pid=fork();
                            if(pid==0){
                                execl("/home/hitesh/Desktop/Assignment/rm","",input[i],NULL,NULL);
                            }else if(pid>0){
                                wait(NULL);
                            }else{
                                printf("Fork is failed");
                            }
                            
                            } 
                    }
                }
            }else if(strcmp(input[0],"date")==0){
                if(total_no_of_words==1){
                    time_t Time;
                    struct tm *tm;
                    time(&Time);
                    tm=localtime(&Time);
                    char buffer[100];
                    strftime(buffer,100,"%a %b %d %X %Z %Y ", tm);
                    printf("%s\n", buffer);
                }else{
                    pid_t pid=fork();
                    if(pid==0){
                        execl("/home/hitesh/Desktop/Assignment/date","/home/hitesh/Desktop/Assignment/date",input[1],NULL,NULL);
                    }else if(pid>0){
                        wait(NULL);
                    }else{
                        printf("Fork is failed");
                    }
                }
            }
        }
    }
 

    return 0;
}
