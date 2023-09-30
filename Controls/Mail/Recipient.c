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
	err = OS_ERR_NONE;
	int i;
	
	//to print first 5 addresses in the mailbox. or what the letter is
	for(i = 0; i<5; i++){
		printf("%c", mailbox[i]);
	}

	//2 second delay
	OSTimeDlyHMSM(0, 
					0, 
					2, 
					0,
					OS_OPT_TIME_HMSM_STRICT, 
					&err);

	//check for errors
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}	
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	err = OS_ERR_NONE;
	CPU_TS ts;

	while(1){
		//sem4 waiting to be signaled 
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ts, &err);
		
		//error check
		if(err != OS_ERR_NONE){
			printf("Error Code:%d\n", err);
		}

		//function call once waiting sem4 is signaled
		readMail();
	}
}
