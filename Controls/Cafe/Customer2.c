#include "Cafe.h"
#include <stdio.h>

/**
 * Customer 2 wants to buy something!
 */

/**
 * @brief Get the FIRST item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 * @param item_name pointer to store what the customer buys
 * @param cost pointer to store the cost of the purchased item
 */
void Customer2_checkout(char** item_name, int* cost) {
	*item_name = menu[0]; // Set val of name to the first menu item
	*cost = costs[0]; // Set val of cost to the first item cost
	printf("\nCurrent business revenue: $%d\n", revenue); // Print revenue before purchase
	OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_PEND_BLOCKING, &ticks, &err); // Wait for register
	checkError(err);
	revenue += *cost; // Add cost of item to revenue
	OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err); // Release register
	checkError(err);
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
		Customer2_checkout(&name, &cost); // Give location of name and cost to checkout function
		printf("\nCustomer 2 order: %s, $%d\n", name, cost); // Print order
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay 3 sec before looping
	}
}
