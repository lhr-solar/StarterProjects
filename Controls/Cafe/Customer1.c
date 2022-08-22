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
	CPU_TS ts;
	*name = menu[3];
	*cost = costs[3];

	OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
	// TODO: error checking
	revenue += *cost;
	printf("Current business revenue: %d\n", revenue);
	OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
	// TODO: error checking
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	
	// Use these pointers as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		Customer1_checkout(&name, &cost);
		print("Customer 1 just bought %s for $%d\n", name, cost);
		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		// TODO: error checking
	}
}
