#include "Mail.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

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
	
	// Timestamp variable for Semaphor pend operations
	CPU_TS ts;

	// Wait for recipient to print past mail
	OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ts, &err);

	// Generate Random Number
	char randomNumberString[4];
	sprintf(randomNumberString, "%d", rand() % 9999);

	// Concatenate message to mailbox
	strcpy(mailbox, "Get your own free pizza at ");
	strcat(mailbox,  randomNumberString);
	strcat(mailbox, " Gullible St!");

	// Signal the recipient 
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err);

	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("depositLetter Error: %d\n", err);
	}
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while(1){
		// Delay for 3 seconds
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);

		// Deposit the letter
		depositLetter();

		// Check for errors and print if present
		if(err != OS_ERR_NONE) {
			printf("Task_Mailman Error: %d", err);
		}
	}
}
