#include "Mail.h"

/**
 * The mailman will put mail in the mailbox.
 */


/**
 * @brief Puts a letter in the mailbox (declared in Tasks.h). The letter must be unique every time
 * this function is called (suggestion: include a random number!). Print "Finished!" at the end.
 */
void depositLetter(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
}

/**
 * @brief Calls depositLetter. Once the letter is deposited, signal the semaphore (effectively putting up the flag).
 * Delay briefly (2-3 seconds) using OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){

	}
}
