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
	//goal is to print out value in mailbox address
	
	int i;
	//a loop to print out the 
	for(i = 0; i<5; i++){
		int num = i;
		mailbox[i] = num;
	}

	//1 sec delay
	OSTimeDlyHMSM(0, 
 				  0, 
				  1, 
				  0,
				  OS_OPT_TIME_HMSM_STRICT, 
				  &err);

	//to print first 5 addresses in the mailbox. or what the letter is
	for(i = 0; i<5; i++){
		printf(mailbox[i]);
	}

	//signal the semaphore 

	
	//finished!
	printf("Finished!");


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
}
