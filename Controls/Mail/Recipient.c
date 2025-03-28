#include "Mail.h"

/**
 * The recipient will read mail from the mailbox.
 */


/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	OSTimeDly (0,0,2,0, OS_OPT_TIME_HMSM_STRICT, &err);
	
	if (err != OS_ERR_NONE){
			printf ("[readMail()] Error Code:%d\n", err);  // if there's an error, print the error code stored in the err variable
			return;
		}
	
	
}
/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){
		readMail();

		if (err != OS_ERR_NONE){
			printf("[Mailman depositLetter()] Error Code:%d\n", err);
		}
		
	}
}
