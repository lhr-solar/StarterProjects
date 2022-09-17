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
	cost=&costs[1];
	name=&menu[1];
	revenue+=costs[1];
	printf("Current Business Revenue: %d", revenue );
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts; 
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	CPU_INT16U seconds = 3000;//3000ms = 3s DELAY
	OS_OPT opt =OS_OPT_TIME_HMSM_STRICT;
	
	while(1){
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);//pendblocking , pendnonblocking doesnt wait, just goes through codes
		if(err!=OS_ERR_NONE){
			printf("Error from OSMutexPend Customer 2");
			return;
		}
		Customer2_checkout(&name,&cost);
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
		if(err!=OS_ERR_NONE){
			printf("Error from OSMutexPost Customer 2");
			return;
		}
		OSTimeDlyHMSM(0,0,seconds,0, opt,&err);
		if(err!=OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Customer 2");
			return;
		}
	}
}
