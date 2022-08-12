#include "os.h"

/**
 * Customer 2 wants to buy something!
 */

/**
 * @brief Acquire the register. Call checkout. After checking out, release the register. Loop.
 */
void Task_Customer_2(void* p_arg){
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){
		
	}
}

/**
 * @brief Get the FIRST item and cost on the menu (Tasks.h). Print the value of this item, along with the corresponding cost. Add the cost to the business revenue and print the current business revenue. Wait for THREE seconds with OSTimeDlyHMSM().
 * 
 * In this method, use ARRAY INDEXING to access values in both arrays.
 */
void Customer2_checkout(){
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
}