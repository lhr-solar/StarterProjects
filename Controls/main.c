#include "MotorController.h"
#include "stdlib.h"
#include <time.h>

void delay(int mseconds){
    clock_t start_time = clock();
    while (clock()<start_time+mseconds){
        ;
    }
}

void main(){
    while(1==1){
        delay(250);
        CANWriter(221,rand());
    }
}