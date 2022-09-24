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
	printf(mailbox); // To read the mail
	printf(err); // Can OS_ERR err be printed? If it works ok, I'll make a function for this
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts; // Store the timestamp for when Mailbox sem is released
	while(1){
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ts, &err); // Wait for mailbox to be free
		readMail(); // Read and print Mailbox contents
		OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err); // release Mailbox
	}
}