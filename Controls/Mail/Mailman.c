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
	//printf("Depositing Letter\n");
	// You should definitely uncomment and actually use this OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	int randomNum = rand(); // Generate and store a random number
	//char letter[256] = randomNum; // Write the random number in the letter
	//printf(*letter); // See if anything actually worked
	//printf("%d\n", randomNum);
	snprintf(mailbox, 256, "You have %d notifications from Duolingo", randomNum);
	//strcpy(mailbox, letter); // Put the letter in the mailbox
	//printf("(The mailbox letter is %s)\n", mailbox);
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	printf("Starting Task_Mailman\n");
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	//CPU_TS ticks;
	while(1){
		OSTimeDlyHMSM(0, 0, 3, 0, OS_OPT_TIME_HMSM_STRICT, &err);
		if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		}
		//OSSemPend(&MailboxFlag_Sem4, 0, OS_OPT_PEND_BLOCKING, &ticks, &err); //Wait for Mailbox to be free
		//printf("The mailman has the mailbox!");
		depositLetter(); // Write to letter
		//printf("Letter has been deposited\n");
		OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_1, &err); // Attempt to post/release mailbox...
		if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		}
	}


}

/*
// Function for printing errors
void printError(OS_ERR err)
{
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}
}*/