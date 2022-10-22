#include "Cafe.h"
#include <stdio.h>

/**
 * Customer 1 wants to buy something!
 */

/**
 * @brief Get the FOURTH item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 * @param item_name pointer to store what the customer buys
 * @param cost pointer to store the cost of the purchased item
 */
void Customer1_checkout(char** item_name, int* cost) {
	OS_ERR err;
	CPU_TS ticks;

	*item_name = menu[3]; // Set value of name to fourth menu item
	*cost = costs[3]; // Set value of cost to fourth item cost
	printf("\nCurrent business revenue: $%d\n", revenue); // Print revenue before purchase
	OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ticks, &err); // Wait for register
	revenue += *cost; // Add value of cost to revenue
	OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err); // Release register
	checkError(err);	
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	
	
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		Customer1_checkout(&name, &cost); // Pass location of name and cost to checkout
		printf("\nCustomer 1 order: %s, $%d\n", name, cost); // Print order
		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay 4 sec before looping
		checkError(err);
	}
}
