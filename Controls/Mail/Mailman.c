#include "Mail.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * The mailman will put mail in the mailbox.
 */


/**
 * @brief Puts a letter in the mailbox (declared in Mail.h). 
 * The letter must be unique every time this function is called (suggestion: include a random number!).
 * Once the letter is deposited, signal the semaphore (effectively putting up the flag).
 * Print "Finished!" at the end.
 */

 // 33 - 125
 #define max_number 125
 #define min_number 0


void depositLetter(void) 
{

	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE

	// for(int i = 0; i < 255; ++i)
	// {
	// 	mailbox[i] = (char) (rand() % (max_number + 1 - min_number) + min_number);
	// }
	// mailbox[255] = '\0';
	strcpy(mailbox, "message, message, message, message");

	OSSemPost(&MailboxFlag_Sem4,  //
			  OS_OPT_POST_1, 
			  &err);

	if(err != OS_ERR_NONE)
	{
		
		printf("Error Code:%d\n", err);
		return 0;
	}

	printf("Finished!\n");
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) 
{

	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	while(1)
	{
	
		depositLetter();

		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);

		if(err != OS_ERR_NONE)
		{
			printf("Error Code:%d\n", err);
			return 0;
		}
	}

}
