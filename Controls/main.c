#include "MotorController.h"
#include "stdlib.h"
#include <time.h>


void timeDelay(int miliseconds){
    clock_t time = (clock()/CLOCKS_PER_SEC)*1000; //convert to milliseconds
    while (((clock()/CLOCKS_PER_SEC)*1000) < time + miliseconds)
    {
        ; //this makes the clock run to create a delay, no code here
    }
}

void main()
{
    while(1)
    {
        timeDelay(100); //prevents the below method from constantly writing to the csv file
        MotorController_Write_to_CAN(221,rand()); //send a random # to the CAN.csv file as a message and the ID 221. These are in the CAN.csv file
    }
}
