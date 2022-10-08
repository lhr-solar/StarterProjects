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
void Customer2_checkout(char** name, int* cost) {
	//OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;

	*name = menu[0];
	*cost = costs[0];

	//Pends Register for Task 2
	OSMutexPend(
			(OS_MUTEX	*)&RegisterOccupied_Mutex,
			(OS_TICK	 )0,
			(OS_OPT		 )OS_OPT_PEND_BLOCKING,
			(CPU_TS		*)&ts,
			(OS_ERR		*)&err);

	if (err != OS_ERR_NONE){
			printf("Error at Task2");
		}

	//4 second delay
	OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err );

	//Update total revenue with Customer 2's order
	revenue +=*cost;

	//Posts Register Mutex after Task 2 is complete
	OSMutexPost(
			(OS_MUTEX	*)&RegisterOccupied_Mutex,
			(OS_OPT		 )OS_OPT_POST_NONE,
			(OS_ERR		*)&err);
	
	//Print order and revenue
	printf("\nCustomer 2 ordered: 	");
	printf("%s",	*name);

	printf("\nBusiness Revenue: 	");
	printf("%d\n", revenue);

	
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		Customer2_checkout(&name, &cost);
	}
	
}
