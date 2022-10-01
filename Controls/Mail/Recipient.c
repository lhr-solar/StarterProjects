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
		printf("Here's the mail: ");
	   	printf("%s\n",mailbox);//mailbox set to random letter
	
	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err );
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;

	while(1){
		OSSemPend(
			&MailboxFlag_Sem4,
			0, 
			OS_OPT_PEND_BLOCKING, 
			&ts, 
			&err);

		readMail();
		if (err != OS_ERR_NONE){
			printf("Error at readMail");
		}
		
	}
}
