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

	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 2 sec.

	if (err != OS_ERR_NONE) {
		printf("[Recipient readMail()] Error Code:%d\n", err);
		return;
	}

	printf("Mail contents: ");
	printf("%s\n", mailbox);
	printf("\nFinished!\n\n");	
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while (1) {
		// Check for message in mailbox
		OSSemPend(&MailboxFlag_Sem4,
				  0,
				  OS_OPT_PEND_BLOCKING,
				  NULL,
				  &err);


		if (err != OS_ERR_NONE) {
			printf("[Recipient Task_Recipient()] Error Code:%d\n", err);
			return;
		} 
		
		printf("Success! Running Task_Recipient...\n");
		readMail();
	}
}
