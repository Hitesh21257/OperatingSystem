#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
	struct tm *tm;
    time_t Time;
	time(&Time);
	tm=localtime(&Time);
	char timing[100];

	if(strcmp(argv[1],"-I")==0){
		strftime(timing,100,"%Y-%m-%d ", tm);
		printf("%s\n", timing);
	}
	else if (strcmp(argv[1],"-R")==0){
		strftime(timing,100,"%a, %d %b %Y %X %Z ", tm);
		printf("%s +0530\n", timing);

	}

}