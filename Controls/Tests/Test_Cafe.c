#include "os.h"
#include "../Tasks.h"
#include "../Cafe/Cafe.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Customer1 and Customer2 tasks here.
 */

// TCB
OS_TCB Cus1TCB;
OS_TCB Cus2TCB;

// STK
CPU_STK Cus1Stk[DEFAULT_STACK_SIZE];
CPU_STK Cus2Stk[DEFAULT_STACK_SIZE];

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
	OSMutexCreate(&RegisterOccupied_Mutex, "Register", &err);

	// If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (register-mutex): %d\n", err);

	// Initialize both tasks here
	// Customer1
	OSTaskCreate(
        (OS_TCB*)&Cus1TCB,
        (CPU_CHAR*)"Mailman",
        (OS_TASK_PTR)Task_Customer_1,
        (void*)NULL,
        (OS_PRIO)TASK_CUS1_PRIO,
        (CPU_STK*)Cus1Stk,
        (CPU_STK_SIZE)WATERMARK_STACK_LIMIT,
        (CPU_STK_SIZE)TASK_MAIL_STACK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)NULL,
        (OS_OPT)(OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err
    );

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (Customer1-task): %d\n", err);

	// Customer2
	OSTaskCreate(
        (OS_TCB*)&Cus2TCB,
        (CPU_CHAR*)"Mailman",
        (OS_TASK_PTR)Task_Customer_2,
        (void*)NULL,
        (OS_PRIO)TASK_CUS2_PRIO,
        (CPU_STK*)Cus2Stk,
        (CPU_STK_SIZE)WATERMARK_STACK_LIMIT,
        (CPU_STK_SIZE)TASK_MAIL_STACK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)NULL,
        (OS_OPT)(OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err
    );

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (Customer2-task): %d\n", err);

	OSStart(&err);	// Start the OS

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (OSStart): %d\n", err);

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
