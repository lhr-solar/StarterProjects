#include "MotorController.h"


void Motor_Control(uint16_t CAN_ID, unsigned long long int CAN_MESSAGE) {
    FILE *fp = fopen("CAN.csv", "w");
    fprintf(fp, "%hu,%llu", CAN_ID, CAN_MESSAGE);
    fclose(fp);
    printf("%hu, %llu\n", CAN_ID, CAN_MESSAGE);
}