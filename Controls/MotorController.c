  
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "MotorController.h"



void MotorController_Write_to_CAN(int CAN_ID, int CAN_MESSAGE) {
    FILE *CanFile = fopen("CAN.csv","w+");
    fprintf(CanFile,"0x%d,%d",CAN_ID,CAN_MESSAGE);
    fclose(CanFile);
}
