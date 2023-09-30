#include "Mail.h"

/**
 * The recipient will read mail from the mailbox.
 */


/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	// Task: Read letter
	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err);	// Delay

	if (err)
		printf("Error code (readMail): %d\n", err);

	printf("%s", mailbox);
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ticks;

	while(1){
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ticks, &err);

		// If no error, OS_ERR_NONE = 0
		if (err)
			printf("Error code (Task_Recipient): %d\n", err);

		// TaskL Read mail
		readMail();
	}
}
