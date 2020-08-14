#include "MotorController.h"
#include "stdlib.h"
#include <time.h>

void delay(int seconds){
    int *mseconds;
    mseconds = seconds*1000;
    clock_t start_time = clock();
    while (clock()<start_time+mseconds){
        ;
    }
}

void main(){
    delay(1);
    CANWriter(221,rand());
}