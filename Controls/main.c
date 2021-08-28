#include "MotorController.h"
#include <stdlib.h>
#include <stdio.h>

// keep above 0
#define DELAY 10000

int delay(int delay){
    while(delay){
        delay--;
    };
    return 0;
}

int main(){
    char* CAN_ID = "242";
    int x = rand() % 1000;
    char CAN_MESSAGE[12];
    sprintf(CAN_MESSAGE, "%d", x);
    while(1){
        int x = rand() % 1000;
        sprintf(CAN_MESSAGE, "%d", x);
        motorcontroller(CAN_ID, CAN_MESSAGE);
        delay(DELAY);
    }
    return 0;
}