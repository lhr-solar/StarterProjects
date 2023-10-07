#include "Mail.h"
#include <stdio.h>

/**
 * The mailman will put mail in the mailbox.
 */

/**
 * @brief Puts a letter in the mailbox (declared in Mail.h). The letter must be unique every time
 * this function is called (suggestion: include a random number!).
 * Once the letter is deposited, signal the semaphore (effectively putting up the flag).
 * Print "Finished!" at the end.
 */
void depositLetter(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	
	static int count = 1;
	sprintf(mailbox, "letter %d", count);
	count++;
	
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err);

	if(err == OS_ERR_NONE){
		printf("Finished!");
	}
	else {
		printf("Value of errno: %d\n", err); 
	}
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {

	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while(1){
		depositLetter();
		OSTimeDlyHMSM(0,
                      0,
                      3,
                      0,
                      OS_OPT_TIME_HMSM_STRICT,
                      &err); 
	}
	if(err != OS_ERR_NONE){
		printf("Value of errno: %d\n", err); 
	}
}
