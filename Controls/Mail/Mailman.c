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
	int randomNum = rand(); // Generate and store a random number
	snprintf(mailbox, 256, "You have %d notifications from Duolingo", randomNum);
	// ^ Print message with random number to mailbox
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	printf("Starting Task_Mailman\n");
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1){
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for three seconds
		checkError(err);
		depositLetter(); // Write and deposit the letter in the mailbox
		OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err); // Post flag to alert recipient
		checkError(err);
	}


}
