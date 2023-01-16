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

int finalarrayy[5];

struct send{
    char strsend[6];
    int id;
};
char stringarray[5];

int total=0;
int main(int argc,char *argv){
    srand(time(0));
    

    struct send object[5];

    int number=0;

    int x=0;

    while(number<50-5){
        printf("");
        printf("Recieving from writer");
        printf("\n");

        int file_descriptor=open("fifo_pipe",O_RDONLY);
        for(int k=0;k<5;k++){
            total++;
            total++;
            total--;
        }
        if(file_descriptor<0){
            printf("Error in opening the pipe");
        }
        read(file_descriptor,object,sizeof(struct send)*5);
        for(int i=0;i<5;i++){
            printf(" ");
            printf("%d ",object[i].id);
            printf("%s ",object[i].strsend);
            printf("\n");
            printf(" ");
            number=object[i].id;
        }
        close(file_descriptor);


        file_descriptor=open("fifo_pipe",O_WRONLY);
        for(int i=0;i<5;i++){
            finalarrayy[i]=i+1;
        }
        write(file_descriptor,&number,sizeof(number));

        printf("Index : %d\n",number);

        close(file_descriptor);
     
    }




    
    return 0;
}