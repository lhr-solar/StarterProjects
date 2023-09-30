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

	if (err != OS_ERR_NONE) {
		printf("[Recipient  readMail()] Error Code:%d\n", err);
	} else {
		OSSemPend(&MailboxFlag_Sem4, 
				  0, 
				  OS_OPT_PEND_BLOCKING, 
				  NULL, 
				  &err);

		printf("Mail contents: \n");

		for (int i = 0; i < 256; i++) {
			printf(mailbox[i]);
		}

		printf("Finished!\n");

		OSSemPost(&MailboxFlag_Sem4, 
				  OS_OPT_POST_ALL, 
				  &err);
	}
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while (true) {
		if (err != OS_ERR_NONE) {
			printf("[Recipient  Task_Recipient()] Error Code:%d\n", err);
			break;
		} else {
			printf("Success! Running Task_Mailman...\n");
		}

		depositLetter();

		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 3 sec.
	}
}
