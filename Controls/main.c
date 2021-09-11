#include "MotorController.h"
#include "stdlib.h"
#include <time.h>


void timeDelay(int mSeconds){
    clock startTime = (clock()/CLOCKS_PER_SEC)*1000; //convert to milliseconds
    while (((clock()/CLOCKS_PER_SEC)*1000)<startTime+mSeconds)
    {
        ; //this makes the clock run to create a delay
    }
}

void main()
{
    while(1)
    {
        timeDelay(200);
        MotorController_Write_to_CAN(221,rand());
    }
}
