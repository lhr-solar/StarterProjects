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

	// Creates Semaphor
	OSSemCreate(&MailboxFlag_Sem4, "Mailbox Flag", 0, &err);

	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("Semaphor Creation Error: %d\n", err);
	}

	// Set a random seed for the random function
	srand(time(NULL));


	// Initialize both tasks here
	OSTaskCreate(
		(OS_TCB*)&Mailman_TCB, 
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
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
		);

	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("Mailman Task Create Error: %d\n", err);
	}


	OSTaskCreate(
		(OS_TCB*)&Recipient_TCB, 
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
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
		);
	
	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("Recipient Task Create Error: %d\n", err);
	}
	
	OSStart(&err);	// Start the OS

	// Check for errors and print if present
	if(err != OS_ERR_NONE) {
		printf("OS Start Error: %d\n", err);
	}

	// Check for errors and print if present

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
