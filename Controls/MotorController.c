#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "MotorController.h"

void CANWriter ( uint16_t CAN_ID, int CAN_MESSAGE) {
    FILE *CANFILE;
    CANFILE = fopen("CAN.csv","w+");
    fprintf(CANFILE,"0x%d,%d",CAN_ID,CAN_MESSAGE);
    fclose(CANFILE);
}