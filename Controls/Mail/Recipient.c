#include "Mail.h"

/**
 * The recipient will read mail from the mailbox.
 */


/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err); //Wait for TWO seconds
	checkError(err);
	printf("The letter says:\n %s\n\n\n\n", mailbox); // To read the mail
	
	
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts; // Store the timestamp for when Mailbox sem is released
	while(1){
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ts, &err); // Wait for mailbox to be free
		checkError(err);
		printf("You just got a letter! I wonder what it says?\n\n");
		readMail(); // Read and print Mailbox contents
		
	}
}