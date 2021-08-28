#include <stdio.h>
#include "MotorController.h"

int motorcontroller(char *CAN_ID, char *CAN_MESSAGE){
    FILE *f = fopen("CAN.csv", "r+");
    if (f == NULL){
        printf("Error opening file!\n");
        return 0;
        // exit(1);
    } else{
        fprintf(f, "0x");
        fprintf(f, CAN_ID);
        fprintf(f, ", ");
        fprintf(f, CAN_MESSAGE);
        fprintf(f, "\n");
        fclose(f);
        return 1;
    }

}