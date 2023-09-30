#include "os.h"
#include "../Tasks.h"
#include "../Mail/Mail.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Mailman and Recipient tasks here.
 */
CPU_STK TaskMailman_Stk[TASK_MAILMAN_STACK_SIZE];
CPU_STK TaskRecipient_Stk[TASK_RECIPIENT_STACK_SIZE];

 // Mailbox semaphore, required by the mailman and recipient tasks
OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

int main(void){
	OS_ERR err;
	err = OS_ERR_NONE;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();
	
	// Create any semaphores/mutexes and initialize any global variables here
	OSSemCreate(&MailboxFlag_Sem4, "mailbox flag", 0, &err);

	// Initializing mailman task
	OSTaskCreate(
		(OS_TCB*)&Mailman_TCB, 
		(CPU_CHAR*)"Mailman", 
		(OS_TASK_PTR)Task_Mailman, 
		(void*)NULL, 
		(OS_PRIO)TASK_MAILMAN_PRIO, 
		(CPU_STK*)TaskMailman_Stk, 
		(CPU_STK_SIZE)TASK_MAILMAN_STACK_SIZE, 
		(CPU_STK_SIZE)TASK_MAILMAN_STACK_SIZE, 
		(OS_MSG_QTY)0,
		(OS_TICK)0, 
		(void*)NULL, 
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
	);

	//check errors
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}
	//Inititializing recipient task
	OSTaskCreate(
		(OS_TCB*)&Recipient_TCB, 
		(CPU_CHAR*)"Recipient", 
		(OS_TASK_PTR)Task_Recipient, 
		(void*)NULL, 
		(OS_PRIO)TASK_RECIPIENT_PRIO, 
		(CPU_STK*)TaskRecipient_Stk, 
		(CPU_STK_SIZE)TASK_RECIPIENT_STACK_SIZE, 
		(CPU_STK_SIZE)TASK_RECIPIENT_STACK_SIZE, 
		(OS_MSG_QTY)0,
		(OS_TICK)0, 
		(void*)NULL, 
		(OS_OPT)(OS_OPT_TASK_STK_CLR), 
		(OS_ERR*)&err
	);

	//error check
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}

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
