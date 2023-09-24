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
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Get name and cost of the item
	*name = menu[3];
	*cost = costs[3];

	// Add to revenue
	revenue += *cost;

	// Print current revenue
	printf("Total revenue is now $%d\n", revenue);
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Timestamp variable for Mutex pend operations
	CPU_TS ts;

	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		// Acquire Register
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

		// Checkout
		Customer1_checkout(&name, &cost);

		// Print name and cost of item
		printf("Customer 1 ordered: %s $%d\n\n", name, cost);

		// Release Register
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_1, &err);

		// Check for errors and print if present
		if(err != OS_ERR_NONE) {
			printf("Task_Customer_1 Error: %d", err);
		}

		// Delay for 4 seconds
		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);
	}
}
