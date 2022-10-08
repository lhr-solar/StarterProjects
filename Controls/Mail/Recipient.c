#include "Mail.h"
#include <stdio.h>

/**
 * The recipient will read mail from the mailbox.
 */


/**
 * @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds.
 */
void readMail(void) {
	
	
	OS_ERR err;		// Make sure to check for errors and print the error code if not OS_ERR_NONE
	
	printf("New Mail: ");
	printf("%s\n\n\n",mailbox);		//mailbox set to random letter
	
	OSTimeDlyHMSM(	(CPU_INT16U)	0, 
					(CPU_INT16U)	0, 
					(CPU_INT16U)	2,
					(CPU_INT32U)	0,
					(OS_OPT)		OS_OPT_TIME_HMSM_STRICT, 
					&err );
	
	if (err != OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Recipient");
		}

}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ts;

	
	while(1){

		//Pends MailboxFlag
		OSSemPend(
			&MailboxFlag_Sem4,
			0, 
			OS_OPT_PEND_BLOCKING, 
			&ts, 
			&err);

		if (err != OS_ERR_NONE){
			printf("Error from OSSemPend Recipient");
		}

		//reads mail
		readMail();
		
	}
}
