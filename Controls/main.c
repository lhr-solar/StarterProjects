#include "MotorController.h"
#include "stdlib.h"
#include <time.h>

void delay(int seconds){
    clock_t start_time = clock();
    while ((clock()/(CLOCKS_PER_SEC))<start_time+seconds){
        ;
    }
}

void main(){
    while(1){
        delay(.250);
        CANWriter(221,rand());
    }
}