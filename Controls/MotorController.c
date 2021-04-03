#include "stdio.h"

void move (int id, char message){
     FILE *fp;
    fp = fopen("/Controls/test.txt/","a");
    fprintf(fp,"%d,%c",id,message);
  
    
    fclose(fp);
    // fscanf(fp,"%s",buff);
    // printf("1: %s/n", buff);
}

int main(void){
  /*  FILE *file;
    char a [50];
    printf("Enter the CAN id and message ");
    scanf("%c",&a);

    return 0;
    */
}