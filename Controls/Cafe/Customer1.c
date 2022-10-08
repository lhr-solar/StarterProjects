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
	//OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;

	*name = menu[3];
	*cost = costs[3];

	//Pends Register for Task 1
	OSMutexPend(
			(OS_MUTEX	*)&RegisterOccupied_Mutex,
			(OS_TICK	 )0,
			(OS_OPT		 )OS_OPT_PEND_BLOCKING,
			(CPU_TS		*)&ts,
			(OS_ERR		*)&err);

	if (err != OS_ERR_NONE){
			printf("Error at Task1");
		}

	//4 second delay
	OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err );

	//Update total revenue with Customer 1's order
	revenue += *cost;

	//Posts Register Mutex after Task 1 is complete
	OSMutexPost(
			(OS_MUTEX	*)&RegisterOccupied_Mutex,
			(OS_OPT		 )OS_OPT_POST_NONE,
			(OS_ERR		*)&err);
	
	//Print order and revenue
	printf("\nCustomer 1 ordered: 	");
	printf("%s",	*name);

	printf("\nItem Cost:		");
	printf("$");
	printf("%d",	*cost);

	printf("\nBusiness Revenue: 	");
	printf("$");
	printf("%d\n", revenue);


	
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		Customer1_checkout(&name, &cost);
	}
	
}
