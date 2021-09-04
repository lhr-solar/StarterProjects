#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void MotorController_SendCAN(int32_t CAN_ID, int64_t CAN_MSG);

#endif