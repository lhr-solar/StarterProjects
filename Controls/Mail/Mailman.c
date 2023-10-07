#include "Mail.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
	err = OS_ERR_NONE;
	int i = 0;

	//a loop to deposit code into mailbox array
	for(i = 0; i<5; i++){
		mailbox[i] = rand() % 9 + '0';
	}
	
	//null terminator for string 
	mailbox[5] = 0;

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
	printf("Finished!\n");

	if(err != OS_ERR_NONE){
			printf("Error Code:%d\n", err);
		}
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	err = OS_ERR_NONE;

	while(1){
		//function call
		depositLetter();

		//3 second delay
		OSTimeDlyHMSM(0, 
					  0, 
					  3, 
					  0,
					  OS_OPT_TIME_HMSM_STRICT, 
					  &err);

		//error check
		if(err != OS_ERR_NONE){
			printf("Error Code:%d\n", err);
		}
	}
}
