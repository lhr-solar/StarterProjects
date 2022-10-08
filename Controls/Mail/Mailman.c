#include "Mail.h"
#include <stdlib.h>
#include <stdio.h>

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
	
	char randNum; //random number generator


	for(int i = 0; i < (5); i++){
		
		randNum = rand()%10 + '0'; //char concatenated to set randNum as chars
		mailbox[i] = randNum; //mailbox contents set to five random 0-9 numbers
	}

	//Delay for 3 seconds
	OSTimeDlyHMSM(	(CPU_INT16U)	0, 
					(CPU_INT16U)	0, 
					(CPU_INT16U)	3,
					(CPU_INT32U)	0,
					(OS_OPT)		OS_OPT_TIME_HMSM_STRICT, 
					&err );
	
	if (err != OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Mailman");
		}

}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	srand(time(NULL)); 

	while(1){
		//deposits letter
		depositLetter();

		//Posts MailboxFlag
		OSSemPost(
				&MailboxFlag_Sem4,
				OS_OPT_POST_1,
				&err);
		
		if (err != OS_ERR_NONE){
			printf("Error from OSSemPost Mailman");
		}

		printf("Finished!\n");
	}
}
