#include "Mail.h"
#include <stdio.h>
#include <stdlib.h>

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

	if (err != OS_ERR_NONE) {
		printf("[Mailman  depositLetter()] Error Code:%d\n", err);
		return;
	} else {
		OSSemPend(&MailboxFlag_Sem4, 
				  0, 
				  OS_OPT_PEND_BLOCKING, 
				  NULL, 
				  &err);

		for (int i = 0; i < 256; i++) {
			mailbox[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
			// Shamelessly taken from https://stackoverflow.com/questions/19724346/generate-random-characters-in-c 
		}
		
		mailbox[256] = '\0';

		printf("Finished!\n");
		
		OSSemPost(&MailboxFlag_Sem4, 
				  OS_OPT_POST_ALL, 
				  &err);
	}
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while (true) {
		if (err != OS_ERR_NONE) {
			printf("[Mailman  Task_Mailman()] Error Code:%d\n", err);
			return;
		} else {
			printf("Success! Running Task_Mailman...\n");
		}

		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 3 sec.
		depositLetter();
	}
}
