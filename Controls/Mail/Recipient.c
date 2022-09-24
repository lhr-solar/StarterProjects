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
	printf("%s\n",mailbox);
	OS_OPT opt =OS_OPT_TIME_HMSM_STRICT;
	OSTimeDlyHMSM(0,0,2,0, opt,&err);//TWO seconds
		if(err!=OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Recipient, readMail");
			return;
		}
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS timestamp;
	while(1){
		OSSemPend(
			&MailboxFlag_Sem4,
			0,
			OS_OPT_PEND_BLOCKING,
			&timestamp,
			&err
			);//pending on mail--is ther any mail yet??
		if(err!=OS_ERR_NONE){
			printf("Error from OSSemPend Mailman");
			return;
		}
		readMail();
	}
}
