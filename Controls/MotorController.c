#include "stdio.h"
#include <stdlib.h>
#include "MotorController.h"
void move (int id, char *message){
    FILE *fp;
    fp = fopen("./CAN.csv","w+");
    if(fp == NULL)
    {
        exit(1);
    }
    fprintf(fp,"%d,%s",id,message);
    message++;
    
    fclose(fp);
    // fscanf(fp,"%s",buff);
    // printf("1: %s/n", buff);
}
