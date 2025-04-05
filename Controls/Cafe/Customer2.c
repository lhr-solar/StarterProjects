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
	*name = menu[0]; // name points to whatever the 4th item is 
	*cost = costs[0]; // cost now holds value of the 4th item

	revenue += (*cost);

	printf("Customer 2: %s\n",*name);
	printf("Total cost : %d\n", *cost);
	printf("Current Revenue : %d\n", revenue);
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
	while(1){
		OSMutexPend (&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, NULL, &err); 
		// 0 in timeout loc because we want to block until mutex is available rather than for a set amount of time
		// null in timestamp location bc its not necessary 

		if (err!=OS_ERR_NONE){
			printf("Error waiting for register: %d\n", err);
			return;
		}

		Customer2_checkout(&name, &cost);

		OSMutexPost (&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);

		if (err!= OS_ERR_NONE){
			printf ("Error posting register: %d\n", err);
			return;
		}

		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);

		if (err!=OS_ERR_NONE){
			printf ("Error in delay : %d\n", err);
			return;
		}

	}
}
