#include "Cafe.h"

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

	// Get the 1st item -- assign name and cost to the pointers passed
	*name = menu[0];
	*cost = costs[0];

	// Add the cost to revenue
	revenue += costs[0];

	// Print current business revenue
	printf("Current business revenue: %d\n", revenue);
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ticks;

	// Return the name and cost into these values from Customer2_checkout
	char* name;
	int cost;
	while(1){
		// Acquire register
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ticks, &err);
		if (err)
			printf("Error code (Cus2 MutexPend): %d\n", err);

		Customer2_checkout(&name, &cost);	// Call checkout
		printf("Customer2 ordered %s. Cost: %d\n", name, cost);	// Print name and cost of item

		// Release register
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
		if (err)
			printf("Error code (Cus2 MutexPost): %d\n", err);
			
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);	// Delay
	}
}
