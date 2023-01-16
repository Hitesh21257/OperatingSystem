#include<stdio.h> 
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h> 
int main(int argc,char *argv[]){
    FILE *point;
    char c;
    // printf("%s\n",argv[0]);
    // printf("%s\n",argv[1]);
    // printf("%s\n",argv[2]);

    if(strcmp(argv[1],"-n")==0){
        int i=1;
        point=fopen(argv[2],"r");
        if(point==NULL){
            printf("Cannot open file\n");
        }else {
            char text[1000];

			while (fgets(text, 1000,point) != NULL) {
		        printf("%d   %s", i, text);
		        i++;
		    }
            
        }

    printf("\n");
    }
    else if(strcmp(argv[1],"-E")==0){
        char line[1000];
        point=fopen(argv[2],"r");
        while(fgets(line,1000,point)!=NULL){
            if(line[strlen(line)-1]=='\n'){
                line[strlen(line)-1]='#';
                printf("%s\n", line);
            }
            else{
                printf("%s", line);
            }
        }
               
    }
    else{
        point=fopen(argv[1],"r");
        if(point==NULL){
            printf("Cannot open file\n");
        }else {
            char text[1000];

			while (fgets(text, 1000, point) != NULL) {
		        printf("%s",text);
		    }
            
            
        }
        printf("\n");
    }
    fclose(point);
    return 0;

}