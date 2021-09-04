#include "MotorController.h"

void MotorController_SendCAN(int32_t CAN_ID, int64_t CAN_MSG){
    
    FILE *fp;
    char str[50] = "CAN.csv";
    fp = fopen(str, "a");
    
    fprintf(fp, "0x%x", CAN_ID);
    fprintf(fp, ",");
    fprintf(fp, "0x%lx\n", CAN_MSG);
    fclose(fp);

    return;
}