#include "os.h"
#include "../Tasks.h"
#include "../Mail/Mail.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Mailman and Recipient tasks here.
 */

 // Mailbox semaphore, required by the mailman and recipient tasks
OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

int main(void){
	OS_ERR err;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();
	
	// Create any semaphores/mutexes and initialize any global variables here
	OSSemCreate(&MailboxFlag_Sem4, "mailbox", 0, &err);
	// TODO: error handling
	

	// Initialize both tasks here
	OSTaskCreate(&Mailman_TCB,
					"mailman",
					Task_Mailman,
					NULL,
					TASK_MAILMAN_PRIO,
					Mailman_Stk,
					TASK_MAILMAN_STACK_SIZE/2,
					TASK_MAILMAN_STACK_SIZE,
					0,
					0,
					NULL,
					OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
					&err);
	// TODO: error handling

	OSTaskCreate(&Recipient_TCB,
					"recipient",
					Task_Recipient,
					NULL,
					TASK_RECIPIENT_PRIO,
					Recipient_Stk,
					TASK_RECIPIENT_STACK_SIZE/2,
					TASK_RECIPIENT_STACK_SIZE,
					0,
					0,
					NULL,
					OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR,
					&err);
	// TODO: error handling
	

	OSStart(&err);	// Start the OS

	printf("=========\nMail Test File\n=========\n");

	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}
	else{
		printf("Success! Running simulator...\n");
	}

	while(1){}	// Infinite loop
	return 0;
}
