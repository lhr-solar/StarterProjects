#include "MotorController.h"
#include "stdlib.h"
#include <time.h>

void delay(int mseconds){
    clock_t start_time = (clock()/CLOCKS_PER_SEC)*1000; //(clock()/clocks_per_sec) = seconds -> (clock()/clocks_per_sec)*1000 = milliseconds
    while (((clock()/CLOCKS_PER_SEC)*1000)<start_time+mseconds){
        ;
    }
}

void main(){
    while(1){
        delay(250);
        CANWriter(221,rand());
    }
}