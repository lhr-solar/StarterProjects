#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "MotorController.h"


/** 

 * @brief   Opens Can.CSV file in w+ to ensure only one entry in the file at a time, writes the given command to the file, and closes it. 

 * @param   CAN_ID The ID of the CAN Command to write to the file
 * @param   CAN_MESSAGE The Message integer to write associated with that CAN_ID

 * @return  void 

 */  
void MotorController_CANWriter ( uint16_t CAN_ID, int CAN_MESSAGE) {
    FILE *CanFile;
    CanFile = fopen("CAN.csv","w+");
    fprintf(CanFile,"0x%d,%d",CAN_ID,CAN_MESSAGE);
    fclose(CanFile);
}