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
void depositLetter(int i, char letter) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	//CPU_TS ts;

	mailbox[i] = letter;

	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1,&err);
	if(err != OS_ERR_NONE){
		printf("Error %d\n", err);
		return;
	}

	return;
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	int i = 0;
	char letter = 'a';

	while(1){
		depositLetter(i, letter);
		OSTimeDlyHMSM(0,0,3,0,OS_OPT_TIME_HMSM_STRICT,&err);
		if (err != OS_ERR_NONE){
			printf("Error %d\n", err);
			return;
		}

		if(i < 255){
			i++;
			letter++;
		}
	}
}
