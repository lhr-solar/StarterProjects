#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief   Transmits motor control msg to CAN.
 * @param   CAN_ID : CAN message ID
 * @param   CAN_MESSAGE : 64-bits - 63-32 = var1, 31-0 = var2
 * @return  None
 */
void Motor_Control(uint16_t CAN_ID, uint64_t CAN_MESSAGE);
