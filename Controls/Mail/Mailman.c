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
	//a loop to deposit code into mailbox array
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

	//signal the semaphore 
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err);

	//print out finished 
	printf("Finished!");

	if(err != OS_ERR_NONE){
			printf("Error: %d", err);
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

		if(err != OS_ERR_NONE){
			printf("Error: %d", err);
		}
	}
}
