#include "Mail.h"
#include <stdio.h>
#include <stdlib.h>
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
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	
	strcpy(mailbox, "You've got mail! ( )");
	mailbox[18] = (rand() % 10) + 48;

	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err);

	printf("Finished!\n");

	if (err != OS_ERR_NONE) {
        printf("depositLetter error code %d\n", err);
    }
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err = OS_ERR_NONE;	// Make sure to check for errors and print the error code if not OS_ERR_NONE

	while(1){
		depositLetter();
		
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);	
	}

	if (err != OS_ERR_NONE) {
        printf("Task_Mailman error code %d\n", err);
    }
}