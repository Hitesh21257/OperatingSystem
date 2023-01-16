#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/un.h>

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

int finalknumber=0;

int main(int argc,char *argv){
    srand(time(0));

    char *finalarray[50];

    int finall[5];

    struct send object[5];
    for(int i=0;i<50;i++){
        finalarray[i]=randomstring();
        // printf("%s\n",finalarray[i]);
    }
    int skt=socket(AF_UNIX,SOCK_STREAM, 0);

    if(skt<0){
        perror("Socket Failed:");
        exit(-1);
    }
    
    struct sockaddr_un writer_addr;

    writer_addr.sun_family = AF_UNIX;

    for(int i=0;i<5;i++){
        finall[i]=i+1;
    }
    
    memcpy(writer_addr.sun_path, "server_socket",sizeof("server_socket")); 
    finalknumber++;
    struct sockaddr_un reader_addr; 
    reader_addr.sun_family = AF_UNIX;  

    finalknumber++; 
    
    memcpy(reader_addr.sun_path, "client_socket",sizeof("client_socket")); 
       
    bind(skt, (struct sockaddr *) &reader_addr, sizeof(reader_addr));


    for(int i=0;i<5;i++){
        finall[i]=i+1;
    }
    
    connect(skt, (struct sockaddr *) &writer_addr, sizeof(writer_addr));

    int number=0;

    

    int x=0;
    

    while(number<50){

        for(int i=0;i<5;i++){
            memcpy(object[i].strsend,finalarray[i],sizeof(finalarray[i]));
            finalknumber++;
            object[i].id=i+x+number;
            finalknumber--;
            finalknumber++;
        }
        send(skt, &object,sizeof(struct send)*5,0);

        for(int i=0;i<5;i++){
            finalknumber++;
        }

        recv(skt,&number,sizeof(number),0);
       
        printf("Index recieved:");
        printf("");
        printf("%d",number);
        printf("\n");
        printf("");
        printf("");
        number++;
     
    }   
    close(skt);
    return 0;
}