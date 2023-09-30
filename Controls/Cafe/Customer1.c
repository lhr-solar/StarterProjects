#include "Cafe.h"

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

	// Get the 4th item -- assign name and cost to the pointers passed
	*name = menu[3];
	*cost = costs[3];

	// Add the cost to revenue
	revenue += costs[3];

	// Print current business revenue
	printf("Current business revenue: %d\n", revenue);
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ticks;

	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		// Acquire register
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ticks, &err);
		if (err)
			printf("Error code (Cus1 MutexPend): %d\n", err);

		Customer1_checkout(&name, &cost);	// Call checkout
		printf("Customer1 ordered %s. Cost: %d\n", name, cost);	// Print name and cost of item

		// Release register
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
		if (err)
			printf("Error code (Cus1 MutexPost): %d\n", err);

		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);	// Delay
	}
}