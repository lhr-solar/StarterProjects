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
			printf("Error from OSMutexPend Customer 2");
		}

	//4 second delay
	OSTimeDlyHMSM(	(CPU_INT16U)	0, 
					(CPU_INT16U)	0, 
					(CPU_INT16U)	4,
					(CPU_INT32U)	0,
					(OS_OPT)		OS_OPT_TIME_HMSM_STRICT, 
					&err );
	
	if (err != OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Customer 2");
		}

	//Update total revenue with Customer 2's order
	revenue +=*cost;

	//Posts Register Mutex after Task 2 is complete
	OSMutexPost(
			(OS_MUTEX	*)&RegisterOccupied_Mutex,
			(OS_OPT		 )OS_OPT_POST_NONE,
			(OS_ERR		*)&err);

	if (err != OS_ERR_NONE){
			printf("Error from OSMutexPost Customer 2");
		}
		
	
	//Print order. item cost, and revenue
	printf("\nCustomer 2 ordered: 	");
	printf("%s",	*name);

	printf("\nItem Cost:		");
	printf("$%d",	*cost);

	printf("\nBusiness Revenue: 	");
	printf("$%d\n", revenue);

	
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
