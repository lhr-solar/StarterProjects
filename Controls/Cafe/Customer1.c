#include "Cafe.h"
#include <stdio.h>

/**
 * Customer 1 wants to buy something!
 */

/**
 * @brief Get the FOURTH item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 */
void Customer1_checkout(char** name, int* cost) {
//	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	*name = menu[3];
	*cost = costs[3];
	revenue += *cost;

}

/**
 * @brief Acquire the cash register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;	


	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		
		OSMutexPend(
			&RegisterOccupied_Mutex, //waits on and acquires this specific mutex
			0, //non binary usage, used for signalling, so 0
			OS_OPT_PEND_BLOCKING, //
			&ts,
			&err
		);
		if (err != OS_ERR_NONE){
			printf("Error %d\n", err);
			return;
		}


		Customer1_checkout(&name, &cost);
		printf("Customer 1:\nName of item is %s and cost of item is %d\n", name, cost);
		printf("Current Business Revenue is %d\n", revenue);


		OSMutexPost(
			&RegisterOccupied_Mutex,
			OS_OPT_POST_NONE,
			&err
		);

		OSTimeDlyHMSM(0,0,4,0,OS_OPT_TIME_HMSM_STRICT, &err);
		if (err != OS_ERR_NONE){
			printf("Error %d\n", err);
			return;
		}

	}


}
