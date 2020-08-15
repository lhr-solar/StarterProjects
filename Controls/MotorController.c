#include <stdio.h>
#include <stdlib.h>
#include "MotorController.h"

void CANWriter ( __UINT16_TYPE__ CAN_ID, int CAN_MESSAGE) {
    FILE *CANFILE;
    CANFILE = fopen("CAN.csv","w+");
    fprintf(CANFILE,"0x%d,%d",CAN_ID,CAN_MESSAGE);
    fclose(CANFILE);
}