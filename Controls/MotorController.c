#Develop code in MotorController.c that will send the appropriate message across the CAN bus in a simulated fashion. 
#This means it will write to the CAN.csv file with the following format: 0xCAN_ID, CAN_MESSAGE. 
#It should accept both the CAN_ID and the CAN_MESSAGE as parameters.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "MotorController.h" 


void MotorController_Write_to_CAN(int CAN_ID, int CAN_MESSAGE) //take parameters CAN_ID and CAN_MESSAGE, gets id of CAN (IN HEX) and message (DRIVE command, a #) 
                                                               //to be sent to CAN
{
  FILE *CANFile =fopen("CAN.csv", w+); //
  fprintf(CANFile, "0x%d,%d", CAN_ID, CAN_MESSAGE); // write to file 
  fclose(CANFile);
}

