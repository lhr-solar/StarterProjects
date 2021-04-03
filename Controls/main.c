#include "MotorController.h"


int main(void){
    while(1)
    {
        move(0x221,"thisIsATest");
        for(int i=0; i<1000000;i++){}
    }
}