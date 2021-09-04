#include "MotorController.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"

void MotorController_SendCAN(int32_t CAN_ID, int64_t CAN_MSG){
    FILE *fp;
    fp = fopen(strcat("CAN", ".csv"), "r+");

    fprintf(fp, "0x%x", CAN_ID);
    fprintf(fp, ", ");
    fprintf(fp, "0x%x", CAN_MSG);
    
    fclose(fp);
    return;
}