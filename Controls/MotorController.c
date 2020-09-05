#include "MotorController.h"


void Motor_Control(uint16_t CAN_ID, uint64_t CAN_MESSAGE) {
    FILE *fp = fopen("CAN.csv", "w");
    fprintf(fp, "%hu, %llu", CAN_ID, CAN_MESSAGE);
}