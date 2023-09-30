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

	// Update parameters
	*name = menu[0];
	*cost = costs[0];

	// Update revenue & display variables
	revenue += *cost;
	printf("%s", *name);
	printf(" costs: %d\n", *cost);
	printf("Business revenue = %d\n", revenue);
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Return the name and cost into these values from Customer2_checkout
	char* name;
	int cost;

	while (1) {
		OSMutexPend((OS_MUTEX*)&RegisterOccupied_Mutex,
					(OS_TICK)0,
					(OS_OPT)OS_OPT_PEND_BLOCKING,
					(CPU_TS*)NULL,
					(OS_ERR*)&err);
		
		if (err != OS_ERR_NONE) {
			printf("[Task_Customer_2()] Error Code: %d\n", err);
			return;
		}

		printf("Success! Running Task_Customer_2...\n");

		Customer2_checkout(&name, &cost);

		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 3 sec.

		OSMutexPost((OS_MUTEX*)&RegisterOccupied_Mutex,
					(OS_OPT)OS_OPT_POST_NONE,
					(OS_ERR*)&err);

		if (err != OS_ERR_NONE) {
			printf("[Task_Customer_2()] Error Code: %d\n", err);
			return;
		}
	}
}
