#include "Cafe.h"

/**
 * Customer 1 wants to buy something!
 */

/**
 * @brief Get the FOURTH item and cost on the menu (Cafe.h). Return the name and cost
 * of the item to the pointers passed into the function. Add the cost to the business 
 * revenue and print the current business revenue.
 */
void Customer1_checkout(char** name, int* cost) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	name = menu[3]; // Set location of "name" to menu[3]
	cost = costs[3]; // Set location of "cost" to costs[3]
	revenue += *cost; // Add value of cost to revenue
	printf("cost: %d\n", cost);
	printf("&cost: %d\n", &cost);
	printf("name: %s\n", name);
	printf("Added to business revenue: $%d\n", *cost);
	printf("New business revenue: $%d\n", revenue);
}

/**
 * @brief Acquire the register. Call checkout. Print the name and cost of the item.
 * After checking out, release the register. Delay for FOUR seconds. Loop.
 */
void Task_Customer_1(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ticks;
	
	// Use these values as parameters for Customer1_checkout
	char* name;
	int cost;
	while(1){
		OSMutexPend(&RegisterOccupied_Mutex, 0, OS_OPT_POST_NONE, &ticks, &err);
		Customer1_checkout(&name, &cost); // Pass location of name and cost to checkout
		printf("Customer 1 order: %s - $%d\n", name, cost);
		OSMutexPost(&RegisterOccupied_Mutex, OS_OPT_POST_NONE, &err);
		OSTimeDlyHMSM(0, 0, 4, 0, OS_OPT_TIME_HMSM_STRICT, &err);
	}
}
