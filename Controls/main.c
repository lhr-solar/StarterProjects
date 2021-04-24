#include "MotorController.h"


int main(void){
    while(1)
    {
        char *char_ptr= "thisIsATest\n";
        char *char_ptr2= "thisIsASecondTest\n"; 
        char *char_ptr3= "thisIsAThirdTest\n";
        char *char_ptr4= "thisIsAFourthTest\n";
        char *char_ptr5= "thisIsAFifthTest\n";
        move(0x221,char_ptr);
        for(int i=0; i<1000000;i++){}
        move(0x221,char_ptr2);
        for(int i=0; i<1000000;i++){}
        move(0x221,char_ptr3);
        for(int i=0; i<1000000;i++){}
        move(0x221,char_ptr4);
        for(int i=0; i<1000000;i++){}
        move(0x221,char_ptr5);
        for(int i=0; i<1000000;i++){}
    }
}