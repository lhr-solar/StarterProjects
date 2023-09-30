#include "Mail.h"

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

	// Desposit letter
	sprintf(mailbox, "Letter %d\n", (rand() % 100));

	// Signal the semaphore
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err);
	printf("Finished!\n");

	// If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (depositLetter): %d\n", err);
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while(1) {
		// Task: Desposit letter
		depositLetter();
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);	// Delay
		
		if (err)
			printf("Error code (Task_Mailman): %d\n", err);
	}
}
