#include "os.h"

/**
 * The recipient will read mail from the mailbox.
 */

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox is signaled, call readMail. Once the letter is deposited, signal the semaphore (effectively putting down the flag). Loop.
 */
void Task_Recipient(void* p_arg){
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){
		
	}
}

/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(){
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
}