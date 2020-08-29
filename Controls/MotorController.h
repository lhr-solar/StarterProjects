#include <stdint.h>

/** 

 * @brief   Writes input to a CAN.csv file to simulate writing to a CAN bus. 

 * @param   CAN_ID The ID of the CAN Command to write to the file
 * @param   CAN_MESSAGE The Message integer to write associated with that CAN_ID

 * @return  void 

 */ 
void MotorController_CANWriter (uint16_t CAN_ID,int CAN_MESSAGE);
