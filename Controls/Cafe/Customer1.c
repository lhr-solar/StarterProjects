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
	*cost=costs[3]; //changed from cost=&costs[3];
	*name=menu[3]; //changed from name=&menu[3];
	revenue+=costs[3];
	printf("Customer 1 Bought a %s\n",*name);
	printf("Current Business Revenue: %d\n", revenue );
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts; 
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	//CPU_INT16U seconds = 4;//4000ms = 4s DELAY
	
	while(1){
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);//pendblocking , pendnonblocking doesnt wait, just goes through codes
		if(err!=OS_ERR_NONE){
			//printf("Error from OSMutexPend Customer 1");
			printf("%x;Error from OSMutexPend Customer 1",err);
			return;
		}
		Customer1_checkout(&name,&cost);
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
		if(err!=OS_ERR_NONE){
			printf("Error from OSMutexPost Customer 1");
			return;
		}
		OSTimeDlyHMSM(
					0,
					0,
					(CPU_INT16U)4,
					0,
					(OS_OPT)OS_OPT_TIME_HMSM_STRICT,
					&err
					);
		if(err!=OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Customer 1");
			return;
		}
	}
}
