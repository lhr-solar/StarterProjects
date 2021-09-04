#include <stdio.h>
#include "MotorController.h"

void wait(int cycles){
    for(int i=0; i<cycles; i++){
        //nothing
    }
}

void main(void){
    
    while(1){
        MotorController_SendCAN(0x221, 0x0);
        printf("send can\n");
        wait(1000);
    }
}

