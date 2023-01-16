#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef struct send{
    int number_id;
    char stringoffive[5][6];
};

char *randomstring(){
    char *alphabet="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char *str=malloc(sizeof(char)*6);
    for(int i=0;i<5;i++){
        str[i]=alphabet[rand()%25];
    }
    str[5]='\0';
    return str;

}

int arrayindex[5];


int main(){

    int shmid  = shmget((key_t)1111, sizeof(struct send),0666);
    for(int i=0;i<5;i++){
        arrayindex[i]=i+1;
    }
    void *shared_memory = shmat(shmid, NULL, 0);

    struct send *ptr = (struct send*)shared_memory;

    int number =0;

    sleep(3);
    while(number<50){
        for(int i = 0;i<5;i++){
            printf("%s\n", ptr->stringoffive[i]);
        }

        ptr->number_id=4+number;
        number=ptr->number_id;
        number++;
        sleep(3);
    }

    return 0;

}
