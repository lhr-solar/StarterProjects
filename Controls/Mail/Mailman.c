#include "Mail.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * The mailman will put mail in the mailbox.
 */


/**
 * @brief Puts a letter in the mailbox (declared in Mail.h). The letter must be unique every time
 * this function is called (suggestion: include a random number!). Print "Finished!" at the end.
 */
void depositLetter(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	int len = (random() % 6) + 3; // Pick a word length between 3 and 8 letters
	for (int i=0; i<len; i++) {
		mailbox[i] = (random() % 26) + 'a';
	}
	mailbox[len] = '\0';
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_ALL, &err);
	// TODO: error handling
	printf("Finished!\n");
}

/**
 * @brief Calls depositLetter. Once the letter is deposited, signal the semaphore (effectively putting up the flag).
 * Delay for THREE seconds using OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){
		depositLetter();
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		// TOOD: error handling
	}
}
