#include "Cafe.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Customer 2 wants to buy something!
 */

/**
 * @brief Get the FIRST item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 */
void Customer2_checkout(char** name, int* cost) {
	*name = menu[0];
	*cost = costs[0];

	revenue += *cost;
	printf("Business revenue: %d\n", revenue);
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
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_POST_NONE, &ticks, &err);
		
		Customer2_checkout(&name, &cost);
		printf("Item: %s\n", name);
		printf("Item cost: %d\n", cost);

		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);

		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);	
	}
	
	if (err != OS_ERR_NONE) {
        printf("Task_Cust2 error code %d\n", err);
    }
}
