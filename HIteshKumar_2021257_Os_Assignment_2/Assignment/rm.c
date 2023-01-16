#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc,char *argv[]){
   if(strcmp(argv[1],"-i")==0){
      char ans;
      printf("Do you wanted to delete this file: (Y/N)");
      scanf("%c",&ans);

      if(ans=='Y'){
         if (remove(argv[1]) == 0)
         printf("Deleted successfully\n");
      else
         printf("Unable to delete the file\n");
      }
      else if(ans=='N'){
         printf("File doesnot deleted");
      }

   }
   else{
      if (remove(argv[1]) == 0)
         printf("Deleted successfully\n");
      else
         printf("Unable to delete the file\n");
   }
  
   return 0;
}