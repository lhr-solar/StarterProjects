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
	*name = menu[3];
	*cost = costs[3];
	revenue += *cost;
	printf("%d\n", revenue);
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
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ticks, &err);
		Customer1_checkout(&name, &cost);
		printf("item: %s\n", name);
		printf("cost: %d\n", cost);
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_ALL, &err);
		OSTimeDlyHMSM(0,
                      0,
                      4,
                      0,
                      OS_OPT_TIME_HMSM_STRICT,
                      &err); 
	}
}
