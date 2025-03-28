#include "Mail.h"



/**
 * The mailman will put mail in the mailbox.
 */


/**
 * @brief Puts a letter in the mailbox (declared in Mail.h). The letter must be unique every time
 * this function is called (suggestion: include a random number!).
 * Once the letter is deposited, signal the semapgithore (effectively putting up the flag).
 * Print "Finished!" at the end.
 */
void depositLetter(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	OSSemPost(&MailboxFlag_Sem4, // address to the semaphore
			  OS_OPT_POST_1, // allows only one waiting task
			  &err); // pointer to the error varriable 

	// Populate the mailbox
	for (int i = 0; i < 256; i++) { // if index is less than 256 (max) 
		mailbox[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26]; // mailbox[i] will get a new random letter
	} // each time the program runs
	mailbox[256] = '\0'; // the end of the string is null terminated

	if (err != OS_ERR_NONE) {
		printf("[Mailman depositLetter()] Error Code:%d\n", err);  // if there's an error, print the error code stored in the err variable
		return;
	} 

	printf("Finished!\n\n");
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) { // void bc we have an input that we don't know the type of
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while (1) {
		printf("Success! Running Task_Mailman...\n"); // err is initially 0 so as long as there's no errors, print success message to indicate Task_Mailman is executing
		
		depositLetter();  // call deposit letter to put message in mailbox
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err); // Delay for only 3 sec. (hrs, mins, seconds, milliseconds)

		if (err != OS_ERR_NONE) {
			printf("[Mailman Task_Mailman()] Error Code: %d\n", err);
			return;
		}
	}
}