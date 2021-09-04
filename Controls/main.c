#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MotorController.h"

void wait(int cycles){
    for(int i=0; i<cycles; i++){
        //nothing
    }
}

void main(void){
    srand(time(NULL));
    while(1){
        MotorController_SendCAN(0x221, rand());
        printf("send can\n");
        wait(1000);
    }
}

