#include "os.h"
#include "../Tasks.h"
#include "../Cafe/Cafe.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Customer1 and Customer2 tasks here.
 */
CPU_STK Task_Customer_1_Stk[TASK_CUST_1_STACK_SIZE];
CPU_STK Task_Customer_2_Stk[TASK_CUST_2_STACK_SIZE];

 // Register mutex, required by the customer tasks
OS_MUTEX RegisterOccupied_Mutex;

char* menu[4] = {"Coffee", "Hot Chocolate", "Pizza", "Donut"}; // Menu (4 items). Feel free to change the menu items.
int costs[4] = {5, 3, 6, 2}; // Costs of the corresponding menu items. Feel free to change these.
int revenue = 0; // Business revenue, increased by the purchasing customers.

int main(void){
	OS_ERR err;
	err = OS_ERR_NONE;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();

	// Create any semaphores/mutexes and initialize any global variables here
	OSMutexCreate(&RegisterOccupied_Mutex, "register mutex", &err);

	// Initialize both customer 1 task
	OSTaskCreate(
		(OS_TCB*)&Customer_1_TCB, 
		(CPU_CHAR*)"Customer 1", 
		(OS_TASK_PTR)Task_Customer_1, 
		(void*)NULL, 
		(OS_PRIO)TASK_CUST_1_PRIO, 
		(CPU_STK*)Task_Customer_1_Stk, 
		(CPU_STK_SIZE)TASK_CUST_1_STACK_SIZE, 
		(CPU_STK_SIZE)TASK_CUST_1_STACK_SIZE, 
		(OS_MSG_QTY)0,
		(OS_TICK)0, 
		(void*)NULL, 
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
	);

	//check errors
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}
	
	//initialize customer 2 task
	OSTaskCreate(
		(OS_TCB*)&Customer_2_TCB, 
		(CPU_CHAR*)"Customer 2", 
		(OS_TASK_PTR)Task_Customer_2, 
		(void*)NULL, 
		(OS_PRIO)TASK_CUST_2_PRIO, 
		(CPU_STK*)Task_Customer_2_Stk, 
		(CPU_STK_SIZE)TASK_CUST_2_STACK_SIZE, 
		(CPU_STK_SIZE)TASK_CUST_2_STACK_SIZE, 
		(OS_MSG_QTY)0,
		(OS_TICK)0, 
		(void*)NULL, 
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
	);

	//check errors
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}

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
