#include "MotorController.h"
#include "stdlib.h"
#include <time.h>


void delay(int mSeconds){
    clock_t startTime = (clock()/CLOCKS_PER_SEC)*1000; //(clock()/clocks_per_sec) = seconds -> (clock()/clocks_per_sec)*1000 = milliseconds
    while (((clock()/CLOCKS_PER_SEC)*1000)<startTime+mSeconds){
        ;
    }
}

void main(){
    while(1){
        delay(250);
        MotorController_CANWriter(221,rand());
    }
}