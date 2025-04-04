#include "Mail.h"

/**
 * The recipient will read mail from the mailbox.
 */


/**
* @brief Print the mail in mailbox. Use an OSTimeDlyHMSM() to wait for TWO seconds. 
*/

void readMail(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	OSTimeDlyHMSM(0, 0, 2, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 2 sec.
	// strict delay
	// pointer to error variable
	
	if (err != OS_ERR_NONE){ // if there is an error
			printf ("Failed to read mail. Error Code:%d\n", err);  // print the error code stored in the err variable
			return;		}
	
		printf("Letter contents: \n %d\n\n\n", mailbox);
}

/**
 * @brief Waits on the mailbox to be signaled. Once the mailbox has signaled, call readMail. Loop
 */
void Task_Recipient(void* p_arg) {
	OS_ERR err;	// error code
	CPU_TS ticks; // time stamp

	// this task will wait for a semaphore, until the depositletter funcion which posts a sempahore
	// use OSSemPend()
	// if sempahore is zero, this function will not execute
	// which is why we use while(1), in order to execute the task

 // use 0 for timeout because any non zero value means that the task will pend for a 
 // certain amout of time. if the semaphore is set within the time, the task occurs, if not
 // the task will stop waiting and time out, issuing a timeout error.

	while(1){
		OSSemPend (&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ticks, &err);
			if (err != OS_ERR_NONE){
			printf("Failure waiting for mail. Error Code:%d\n", err);
			return;
			}
			printf ("You have 1 incoming letter!\n\n");
			readMail ();
	}
}