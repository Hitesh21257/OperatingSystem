#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>

char *randomstring(){
    char *alphabet="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char *str=malloc(sizeof(char)*6);
    for(int i=0;i<5;i++){
        str[i]=alphabet[rand()%25];
    }
    str[5]='\0';
    return str;

}
typedef struct send{
    int number_id;
    char stringoffive[5][6];
}send;

int main(){

    srand(time(0));

    clock_t staring;
    clock_t ending;

    starting=clock();

    int arrayindex[5];

    char *finalarray[50];

    struct send object;

    for(int i=0;i<50;i++){
        finalarray[i]=randomstring();
    }

    key_t key=ftok("shmfile",69);
    

    int shmid=shmget((key_t)1111,sizeof(struct send),0666|IPC_CREAT);

    void * shared = shmat(shmid, NULL,0);
    for(int i=0;i<5;i++){
        arrayindex[i]=i+1;
    }
    struct send *ptr = (struct send*)shared;
    int number=0;
    int x=0;

    while(number<50){

        for(int i=0;i<5;i++){
            arrayindex[i]=i+number;
        }

        for(int i=0;i<5;i++){
            if(i+number <= 49){
                strcpy(ptr->stringoffive[i],finalarray[i+number]);
            }else{
        printf("\n");
        printf("Index ");
        printf("Recieved :");
        printf("%d ",ptr->number_id);
            return 0;
            }
        }
        sleep(3);
        printf(" ");
        printf("\n");
        printf("Index ");
        printf("Recieved:" );
        printf("%d \n",ptr->number_id);
        number=ptr->number_id;
        number++;

    }


    ending=clock();
    printf("Time taken %f",(double) (ending-starting));
    
}
