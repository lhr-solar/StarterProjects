#include "os.h"
#include "../Tasks.h"
#include "../Mail/Mail.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Create and test the functionality of the Mailman and Recipient tasks here.
 */

 // Mailbox semaphore, required by the mailman and recipient tasks
OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

int main(void) {
	OS_ERR err;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();
	
	// Create any semaphores/mutexes and initialize any global variables here
	OSSemCreate(&MailboxFlag_Sem4, 
				"Mailbox Sem4", 
				0, 
				&err);

	// Initialize both tasks here
	Task_Mailman();
	Task_Recipient();

	OSStart(&err);	// Start the OS

	printf("=========\nMail Test File\n=========\n");

	if (err != OS_ERR_NONE) {
		printf("Error Code:%d\n", err);
		return 0;
	} else {
		printf("Success! Running simulator...\n");
	}

	while (true) {
		
	}	// Infinite loop


	return 0;
}
