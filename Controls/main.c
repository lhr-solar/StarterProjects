#include "MotorController.h"
#include "stdlib.h"
#include <time.h>


void timeDelay(int mSeconds){
    clock_t startTime = (clock()/CLOCKS_PER_SEC)*1000; //convert to milliseconds
    while (((clock()/CLOCKS_PER_SEC)*1000)<startTime+mSeconds)
    {
        ; //this makes the clock run to create a delay
    }
}

void main()
{
    while(1)
    {
        timeDelay(100);
        MotorController_Write_to_CAN(221,rand()); //send a random # as a message every time to the ID 221
    }
}
