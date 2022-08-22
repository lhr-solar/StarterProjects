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
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;
	*name = menu[0];
	*cost = costs[0];

	OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
	// TODO: error checking
	revenue += *cost;
	printf("Current business revenue: %d\n", revenue);
	OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
	// TODO: error checking
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Return the name and cost into these pointers from Customer2_checkout
	char* name;
	int cost;
	while(1){
		Customer2_checkout(&name, &cost);
		printf("Customer 2 just bought %s for $%d\n", name, cost);
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		// TODO: error checking
	}
}
