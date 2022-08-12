#include "os.h"

/**
 * The mailman will put mail in the mailbox.
 */

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox is signaled, call depositLetter. Once the letter is deposited, signal the semaphore (effectively putting up the flag). Loop.
 */
void Task_Mailman(void* p_arg){
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){

	}
}

/**
 * @brief Puts a letter in the mailbox (declared in Tasks.h). The letter must be unique every time this function is called (suggestion: include a random number!). Use an OSTimeDlyHMSM() to wait for THREE seconds, and print "Finished!" at the end.
 */
void depositLetter(){
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
}