#include "Mail.h"
#include <stdio.h>


/**
 * The recipient will read mail from the mailbox.
 */


/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Print the message
	printf("%s\n", mailbox);

	// Delay for 2 seconds
	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err);

	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("readMail Error: %d\n", err);
	}
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Timestamp variable for Semaphor pend operations
	CPU_TS ts;

	while(1){
		// Wait for mailman to post a message to the mailbox
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

		if(err != OS_ERR_NONE) {
			printf("Task_Recipient Error: %d\n", err);
		}

		// Check the mailbox
		readMail();
	}
}
