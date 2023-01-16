#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<semaphore.h>



sem_t forkk[5];
sem_t bowl;
void semaphore_initilize(){
    sem_init(&bowl, 0, 2);
    for(int i=0;i<5;i++){
        printf("");
        printf("semaphore_initilize()");
        printf("");
        printf("\n");
        sem_init(&forkk[i],0,1);
    }
}

int a[5]={0,1,2,3,4};

void *eatpattern(void *number){
    printf("");
    int philosNum=*((int *)number);
    while(1){
        printf("");
        printf("\n");
        printf("Sem_wait \n");
        printf("\n");
        sleep(0.02);
        if (philosNum == 4){
            sem_wait(&forkk[(philosNum+2-1)%5]);
            sem_wait(&forkk[philosNum]);
        }
        else {
            sem_wait(&forkk[philosNum]);
            sem_wait(&forkk[(philosNum+2-1)%5]);
        }
        printf("Philospher number %d is eating\n",philosNum+2-1);
        sem_wait(&bowl);
        sleep(0.001);

        printf("\n");
        printf("");
        printf("Philospher number %d is complete its food\n",philosNum+2-1);
        printf("Sem_post()\n");
        sem_post(&forkk[((philosNum+2-1)%5)]);
        sem_post(&forkk[philosNum]);
        sem_post(&bowl);

        printf("");
    }
}
int main(){
    pthread_t pid[5];
    semaphore_initilize();

    printf("Thread1 is created()\n");
    pthread_create(&pid[0],NULL,eatpattern,(void *)&a[0]);
    printf("Thread2 is created()\n");
    pthread_create(&pid[1],NULL,eatpattern,(void *)&a[1]);
    printf("Thread3 is created()\n");
    pthread_create(&pid[2],NULL,eatpattern,(void *)&a[2]);
    printf("Thread4 is created()\n");
    pthread_create(&pid[3],NULL,eatpattern,(void *)&a[3]);
    printf("Thread5 is created()\n");
    pthread_create(&pid[4],NULL,eatpattern,(void *)&a[4]);

    
    printf("Thread1 is joined()\n");
    pthread_join(pid[0],NULL);
    printf("Thread2 is joined()\n");
    pthread_join(pid[1],NULL);
    printf("Thread3 is joined()\n");
    pthread_join(pid[2],NULL);
    printf("Thread4 is joined()\n");
    pthread_join(pid[3],NULL);
    printf("Thread5 is joined()\n");
    pthread_join(pid[4],NULL);

    
}