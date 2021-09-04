#include "MotorController.h"

int main(void){
    int c=0;
    while(1){
        if(c > 1000){
            MotorController_SendCAN(0x221, 0x0);
            c=0;
        }
        c++;
    }
}