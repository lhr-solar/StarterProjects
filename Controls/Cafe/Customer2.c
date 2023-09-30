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
	err = OS_ERR_NONE;

	//assigning values to pointers in function
	name = menu[0];
	cost = costs[0];

	//adding cost of the menu item to business revenue 
	revenue = revenue + costs[0];

	// printing out new business revenue 
	printf("Business revenue: $%d", revenue);

	//error check 
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}	
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for THREE seconds. Loop.
 */
void Task_Customer_2(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	err = OS_ERR_NONE; 
	CPU_TS ts;

	//lock the register for use 
	OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

	//calling the checkout function
	Customer2_checkout(name, cost);

	//printing out the customer receipt
	printf("Customer name: %c, Cost: %d", name, cost);

	//release the register 		
	OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);

	//4 second delay 
	OSTimeDlyHMSM(0, 
				0, 
				3, 
				0,
				OS_OPT_TIME_HMSM_STRICT, 
			&err);

	//check for errors
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}	
}

