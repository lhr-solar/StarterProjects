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
	char letter[256] = rand(); // Initialize letter with a random number
	printf(letter); // See if anything actually worked
	strcopy(mailbox, letter); // Put the letter in the mailbox
	printf("Finished?"); 
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	CPU_TS ticks;
	while(1){
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, err);
		OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ticks, &err); //Wait for Mailbox to be free
		depositLetter(); // Write to letter
		OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err); // Attempt to post/release mailbox...

	}
}
