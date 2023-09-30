#include "os.h"
#include "../Tasks.h"
#include "../Mail/Mail.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

	if (errReport("Sem4", err)) {
		return 0;
	}
/*
	if (err != OS_ERR_NONE) {
		printf("Sem4 Error: %d\n", err);
		return 0;
	}
*/
	
	// Initialize both tasks here
	OSTaskCreate((OS_TCB*)&Mailman_TCB, 
				 (CPU_CHAR*)"Mailman Task", 
				 (OS_TASK_PTR)Task_Mailman, 
				 (void*)NULL, 
				 (OS_PRIO)TASK_MAILMAN_PRIO, 
				 (CPU_STK*)&Mailman_Stk, 
				 (CPU_STK_SIZE)TASK_MAILMAN_STACK_SIZE / 2, 
				 (CPU_STK_SIZE)TASK_MAILMAN_STACK_SIZE, 
				 (OS_MSG_QTY)0, 
				 (OS_TICK)0, 
				 (void*)NULL, 
				 (OS_OPT)OS_OPT_TASK_STK_CLR, 
				 (OS_ERR*)&err);

	if (err != OS_ERR_NONE) {
		printf("Mailman Task Create Error: %d\n", err);
		return 0;
	}

	printf("Created mailman task");

	OSTaskCreate((OS_TCB*)&Recipient_TCB, 
				 (CPU_CHAR*)"Recipient Task", 
				 (OS_TASK_PTR)Task_Recipient, 
				 (void*)NULL, 
				 (OS_PRIO)TASK_RECIPIENT_PRIO, 
				 (CPU_STK*)&Recipient_Stk, 
				 (CPU_STK_SIZE)TASK_RECIPIENT_STACK_SIZE / 2, 
				 (CPU_STK_SIZE)TASK_RECIPIENT_STACK_SIZE, 
				 (OS_MSG_QTY)0, 
				 (OS_TICK)0, 
				 (void*)NULL, 
				 (OS_OPT)OS_OPT_TASK_STK_CLR, 
				 (OS_ERR*)&err);

	printf("Created recipient task");

	
	OSStart(&err);	// Start the OS

	printf("=========\nMail Test File\n=========\n");

	if (err != OS_ERR_NONE) {
		printf("Error Code:%d\n", err);
		return 0;
	}

	printf("Success! Running simulator...\n");

	// Infinite loop so tasks keep alternating and main() does not terminate
	while (1) {}	

	return 0;
}

/**
 * Print out the error if one exists. Returns true if there is an error, false otherwise.
 * @param str is the error code string
 * @param err is the error code
 */
int errReport(char str[], OS_ERR err) {
	if (err != OS_ERR_NONE) {
		printf("Error: %s", str);
		printf(" Code:%d\n", err);
		return 1;
	}

	return 0;
} 
