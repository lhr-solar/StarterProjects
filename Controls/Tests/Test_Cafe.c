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
		&RegisterOccupied_Mutex, 
		"Register", 
		&err);

	// Initialize both tasks here
	OSTaskCreate(
		(OS_TCB			*)&Customer_1_TCB,
        (CPU_CHAR		*)"Customer 1",
        (OS_TASK_PTR	 )Task_Customer_1,
        (void			*)NULL,
        (OS_PRIO		 )TASK_CUST_1_PRIO,
        (CPU_STK		*)&Customer_1_Stk[0],
        (CPU_STK_SIZE	 )TASK_CUST_1_STACK_SIZE/10,
        (CPU_STK_SIZE    )TASK_CUST_1_STACK_SIZE,
        (OS_MSG_QTY		 )0,
        (OS_TICK		 )0,
        (void			*)NULL,
        (OS_OPT			 )OS_OPT_TASK_STK_CLR,
        (OS_ERR			*)&err);

	OSTaskCreate(
		(OS_TCB			*)&Customer_2_TCB,
        (CPU_CHAR		*)"Customer 2",
        (OS_TASK_PTR	 )Task_Customer_2,
        (void			*)NULL,
        (OS_PRIO		 )TASK_CUST_2_PRIO,
        (CPU_STK		*)&Customer_2_Stk[0],
        (CPU_STK_SIZE	 )TASK_CUST_2_STACK_SIZE/10,
        (CPU_STK_SIZE    )TASK_CUST_2_STACK_SIZE,
        (OS_MSG_QTY		 )0,
        (OS_TICK		 )0,
        (void			*)NULL,
        (OS_OPT			 )OS_OPT_TASK_STK_CLR,
        (OS_ERR			*)&err);

	OSStart(&err);	// Start the OS

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
