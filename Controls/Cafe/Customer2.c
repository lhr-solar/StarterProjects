#include "Cafe.h"
#include <stdio.h>

/**
 * Customer 2 wants to buy something!
 */

/**
 * @brief Get the FIRST item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 */
void Customer2_checkout(char** name, int* cost) {
//	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	*name = menu[0];
	*cost = costs[0];
	revenue += *cost;
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;
	// Return the name and cost into these values from Customer2_checkout
	char* name;
	int cost;
	while(1){
		OSMutexPend(
			&RegisterOccupied_Mutex,
			0,
			OS_OPT_PEND_BLOCKING,
			&ts,
			&err
		);
		if (err != OS_ERR_NONE){
			printf("Error %d", err);
			return;
		}

		Customer2_checkout(&name, &cost);
		printf("Customer 2:\nName of item is %s and cost of item is %d\n", name, cost);
		printf("Current business revenue is %d\n", revenue);


		OSMutexPost(
			&RegisterOccupied_Mutex,
			OS_OPT_POST_NONE,
			&err
		);
		if (err != OS_ERR_NONE){
			printf("Error %d", err);
			return;
		}

		OSTimeDlyHMSM(0,0,4,0,OS_OPT_TIME_HMSM_STRICT,&err);
		if (err != OS_ERR_NONE){
			printf("Error %d", err);
			return;
		}
	}
}
