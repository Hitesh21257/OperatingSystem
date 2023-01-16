#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

char *randomstring(){
    char *alphabet="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char *str=malloc(sizeof(char)*6);
    for(int i=0;i<5;i++){
        str[i]=alphabet[rand()%25];
    }
    str[5]='\0';
    return str;

}
struct send{
    char strsend[6];
    int id;
};
int finalnumber=0;

int main(int argc,char *argv){

    clock_t starting;
    clock_t ending;

    starting=clock();

    srand(time(0));

    char *finalarray[50];

    //pipe created

    int pipe=mkfifo("fifo_pipe",0666);

    if(pipe<0){
        perror("pipe doesnot created:");
        exit(-1);
        
    }

    struct send object[5];

    int number=0;

    for(int i=0;i<50;i++){
        finalarray[i]=randomstring();
    }
    int x=0;

    int arr[5];

    while(number<50){

        int file_descriptor=open("fifo_pipe",O_WRONLY);
        for(int i=0;i<5;i++){
            finalnumber++;
        }
        if(file_descriptor<0){
            printf("Error in opening the pipe");
        }
        for(int i=0;i<5;i++){
            finalnumber++;
            memcpy(object[i].strsend,finalarray[i+number],sizeof(finalarray[i]));
            finalnumber++;
            object[i].id=i+x+number;
            finalnumber--;
        }
        write(file_descriptor,object,sizeof(struct send)*5);

        for(int i=0;i<5;i++){
            arr[i]=i+1;
        }
        close(file_descriptor);
        
        file_descriptor=open("fifo_pipe",O_RDONLY);

        for(int i=0;i<5;i++){
            finalnumber+=i;
        }

        read(file_descriptor,&number,sizeof(number));

        printf("Index recieved:");
        printf("");
        printf("%d",number);
        printf("\n");
        printf("");
        number++;

        close(file_descriptor);
     
    }  
    ending=clock(); 

    printf("Time taken %f",(double) (ending-starting));
    return 0;
}