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

int finalsocket[5];

int totalnumber=0;

int main(int argc,char *argv){

    srand(time(0));

    clock_t starting;
    clock_t ending;

    starting=clock();

    char *finalarray[50];

    struct send object[5];

    int w_skt=socket(AF_UNIX,SOCK_STREAM, 0);

    if(w_skt<0){
        perror("Socket Failed:");
        exit(-1);
    }
    struct sockaddr_un writer_addr;
    writer_addr.sun_family = AF_UNIX;
    int h=0;

    while(h<5){
        totalnumber++;
        h++;
    }
    strcpy(writer_addr.sun_path, "server_socket");

    int size =sizeof(writer_addr);

    unlink("server_socket");
    for(int i=0;i<5;i++){
        finalsocket[i]=i+1;
    }
    bind(w_skt, (struct sockaddr *) &writer_addr, size);
    totalnumber++;
    listen(w_skt, 10);

    struct sockaddr_un reader_addr; 

    int r_sock = accept(w_skt, (struct sockaddr *) &reader_addr, &size);
    size = sizeof(reader_addr);
    for(int i=0;i<5;i++){
        totalnumber++;
    }
    getpeername(r_sock, (struct sockaddr *) &reader_addr, &size);

    int number=0;
    int x=0;
    

    while(number<50-5){

        printf("Recieve from writer");
        for(int i=0;i<5;i++){
            totalnumber++;
        }
        recv(r_sock,&object,sizeof(struct send)*5,0);

        for(int i=0;i<5;i++){
            printf("%d ",object[i].id);
            printf("%s ",object[i].strsend);
            printf("\n");
            number=object[i].id;
            totalnumber++;
        }
        send(r_sock,&number,sizeof(number),0);

        // close(file_descriptor);
     
    }   
    close(r_sock);
    close(w_skt);
    ending=clock(); 

    printf("Time taken %f",(double) (ending-starting));

    return 0;
}