#include "MotorController.h"

void CAN_Test_1(void);
uint8_t msg;
uint16_t CAN_ID;
unsigned long long int CAN_MESSAGE;
void main(){
    srand(time(0));
    //msg = 0;    //CAN_ID counter
    //CAN_ID = 0;
    CAN_ID = 0x221;
    // Motor_Control(CAN_ID, 0x11110000);
    while(1){
        // switch(msg){
        //     case 0x0:
        //         CAN_ID = 0x221;
        //         break;
        //     case 0x1:
        //         CAN_ID = 0x222;
        //         break;
        //     case 0x2:
        //         CAN_ID = 0x223;
        //         break;
        //     case 0x3:
        //         CAN_ID = 0x243;
        //         break;
        // }
        // msg = (msg+1)%4;
        CAN_Test_1();
    }
}  
void CAN_Test_1(void){
    for(int i = 0; i < 0x10000000; i++){
        }
        CAN_MESSAGE = ((rand() % 0xFFFFFFFFFFFFFFF))<<32;
        CAN_MESSAGE += (rand() % 0xFFFFFFFFFFFFFFF);
        Motor_Control(CAN_ID, CAN_MESSAGE);
        //printf("%hu, %llu\n", CAN_ID, CAN_MESSAGE);
        // printf("0x%hx\n", CAN_ID);
        // printf("0x%llX\n", CAN_MESSAGE);
}