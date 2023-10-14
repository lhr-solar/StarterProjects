#include "Cafe.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Customer 2 wants to buy something!
 */

/**
 * @brief Get the FIRST item and cost on the menu (Cafe.h). 
 Return the name and cost of the item to the pointers 
 passed into the function. 
 Add the cost to the business revenue and 
 print the current business revenue.
 */
void Customer2_checkout(char** name, int* cost) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	//printf("Customer 2 checkout\n");
	*name = menu[0];
	*cost = costs[0];
	revenue += costs[0];
	printf("Current revenue: %d\n", revenue);
}

/**
 * @brief Acquire the register. 
 		Call checkout. 
		Print the name and cost of the item.
 * 		After checking out, release the register. 
 		Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;
	
	if(err != OS_ERR_NONE)
	{
		printf("Error Code:%d\n", err);
		return 0;
	}
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1)
	{
			OSMutexPend(
				(OS_MUTEX*) &RegisterOccupied_Mutex, 
				(OS_TICK) 0, 
				(OS_OPT) OS_OPT_PEND_BLOCKING,
				(CPU_TS*) &ts, 
				(OS_ERR*) &err
			);
			if(err != OS_ERR_NONE)
			{
				printf("Error Code:%d\n", err);
				return 0;
			}
			Customer2_checkout(&name, &cost);
			printf("Name: %s, cost: %d\n", name, cost);
			OSMutexPost(
				(OS_MUTEX*) &RegisterOccupied_Mutex, 
				(OS_OPT) OS_OPT_POST_NONE, 
				(OS_ERR*) &err
			);
			if(err != OS_ERR_NONE)
			{
				printf("Error Code:%d\n", err);
				return 0;
			}

			OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);
			if(err != OS_ERR_NONE)
			{
				printf("Error Code:%d\n", err);
				return 0;
			}

	}

	
}
