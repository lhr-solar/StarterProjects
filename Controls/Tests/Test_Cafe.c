#include "os.h"
#include "../Tasks.h"
#include "../Cafe/Cafe.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Customer1 and Customer2 tasks here.
 */

 // Register mutex, required by the customer tasks
OS_MUTEX RegisterOccupied_Mutex;

char* menu[4] = {"Coffee", "Hot Chocolate", "Pizza", "Donut"}; // Menu (4 items). Feel free to change the menu items.
int costs[4] = {5, 3, 6, 2}; // Costs of the corresponding menu items. Feel free to change these.
int revenue = 0; // Business revenue, increased by the purchasing customers.

int main(void){
	OS_ERR err;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();

	// Create any semaphores/mutexes and initialize any global variables here
	OSMutexCreate(
		(OS_MUTEX*) &RegisterOccupied_Mutex, 
		(CPU_CHAR*) "Register Mutex", 
		(OS_ERR*) &err);


	OS_TCB Customer1_TCB;
	OS_TCB Customer2_TCB;

	CPU_STK	Customer1Stk[256];
	CPU_STK Customer2Stk[256];
	// Initialize both tasks here

	OSTaskCreate
	(
        (OS_TCB*)     &Customer1_TCB,
        (CPU_CHAR*)   "Customer 1",
        (OS_TASK_PTR) Task_Customer_1,
        (void*)       NULL,
        (OS_PRIO)     2,
        (CPU_STK*)    Customer1Stk,
        (CPU_STK_SIZE)128/10,
        (CPU_STK_SIZE)256,
        (OS_MSG_QTY)  0,
        (OS_TICK)     0,
        (void*)       NULL,
        (OS_OPT)      (OS_OPT_TASK_STK_CLR),
        (OS_ERR*)     &err
    );

	OSTaskCreate
	(
        (OS_TCB*)     &Customer2_TCB,
        (CPU_CHAR*)   "Customer 2",
        (OS_TASK_PTR) Task_Customer_2,
        (void*)       NULL,
        (OS_PRIO)     2,
        (CPU_STK*)    Customer2Stk,
        (CPU_STK_SIZE)128/10,
        (CPU_STK_SIZE)256,
        (OS_MSG_QTY)  0,
        (OS_TICK)     0,
        (void*)       NULL,
        (OS_OPT)      (OS_OPT_TASK_STK_CLR),
        (OS_ERR*)     &err
    );
	

	

	OSStart(&err);	// Start the OS
	printf("got here\n");

	printf("=========\nCafe Test File\n=========\n");

	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}
	else{
		printf("Success! Running simulator...\n");
	}

	while(1){}	// Infinite loop
	return 0;
}
