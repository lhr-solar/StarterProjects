#include "Mail.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * The mailman will put mail in the mailbox.
 */


/**
 * @brief Puts a letter in the mailbox (declared in Mail.h). The letter must be unique every time
 * this function is called (suggestion: include a random number!).
 * Once the letter is deposited, signal the semaphore (effectively putting up the flag).
 * Print "Finished!" at the end.
 */
//extern char* mailbox;
void depositLetter(void) {
	OS_ERR err; // Make sure to check for errors and print the error code if not OS_ERR_NONE
	//int i;
	//char max=random()%255;//different lengths at diff times
	for(int i=0;i<255;i++){
		mailbox[i]=64+rand()%63;
	}
	mailbox[256]=0;//null at end
	OSSemPost(&MailboxFlag_Sem4, OS_OPT_POST_NONE, &err);//post +1 mail in box
		if(err!=OS_ERR_NONE){
			printf("Error from OSSemPost Mailman, depositLetter");
			return;
		}
	printf("Finished!\n");
}

/**
 * @brief Calls depositLetter. Delay for THREE seconds using 
 * OSTimeDlyHMSM(). Loop.
 */
void Task_Mailman(void* p_arg) {
	OS_ERR err;	// Make sure to check for errors and print the error code if not OS_ERR_NONE
	//CPU_TS ts; 
	
	CPU_INT16U seconds = 3;//3000ms = 3s DELAY
	OS_OPT opt =OS_OPT_TIME_HMSM_STRICT;
	while(1){
		depositLetter();
		OSTimeDlyHMSM(0,0,seconds,0, opt,&err);
		if(err!=OS_ERR_NONE){
			printf("Error from OSTimeDlyHMSM Task_Mailman");
			return;
		}
	}
}
