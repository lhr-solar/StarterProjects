#include <stdio.h>
#include <stdlib.h>
#include "MotorController.h"

void CANWriter ( int CAN_ID, int CAN_MESSAGE) {
    FILE *CANFILE;
    CANFILE = fopen("CAN.csv","w+");
    fprintf(CANFILE,"0x%d,%d",CAN_ID,CAN_MESSAGE);
    fclose(CANFILE);
}