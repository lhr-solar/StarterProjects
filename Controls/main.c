#include "MotorController.h"

void CAN_Test_1(void);
uint8_t msg;
uint16_t CAN_ID;
uint64_t CAN_MESSAGE;
time_t t;
void main(){
    srand((unsigned) time(&t));
    msg = 0;    //CAN_ID counter
    CAN_ID = 0;
    MotorControl(0x16, 0x11110000);
    /*
    while(1){
        switch(msg){
            case 0x0:
                CAN_ID = 0x221;
                break;
            case 0x1:
                CAN_ID = 0x222;
                break;
            case 0x2:
                CAN_ID = 0x223;
                break;
            case 0x3:
                CAN_ID = 0x243;
                break;
        }
        msg = (msg+1)%4;
        CAN_Test_1();
    }
}  
void CAN_Test_1(void){
    for(int i = 0; i < 0x1000000; i++){
        }
        CAN_MESSAGE = (rand() % 0x1000000000000000);
        CAN_MESSAGE = CAN_MESSAGE<<48;
        CAN_MESSAGE += (rand() % 0x1000000000000000);
        Motor_Control(CAN_ID, CAN_MESSAGE);
        */
}