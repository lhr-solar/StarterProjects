#include "../uCOS-III-Simulator/uCOS-III/Source/os.h"
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
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}

	OS_CPU_SysTickInit();
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}	
	
	// Create any semaphores/mutexes and initialize any global variables here
	OSSemCreate(
		&MailboxFlag_Sem4, //semaphore to be used
		"Semaphore",
		0, //Use 0 since sem is used for signalling (technically not binary)
		&err
		);	

	// Initialize both tasks here

	OSTaskCreate(
		(OS_TCB*)&Mailman_TCB,
		(CPU_CHAR*)"Mailman Failed...\n",
		(OS_TASK_PTR) Task_Mailman,
		(void*) NULL,
		(OS_PRIO) TASK_MAILMAN_PRIO,
		(CPU_STK*) Mailman_Stk,
		(CPU_STK_SIZE) TASK_MAILMAN_STACK_SIZE,
		(CPU_STK_SIZE) TASK_MAILMAN_STACK_SIZE,
		(OS_MSG_QTY) 0,
		(OS_TICK) 0,
		(void*) NULL,
		(OS_OPT) OS_OPT_TASK_STK_CLR,
		(OS_ERR*) &err
	);
			
	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}

	OSTaskCreate(
		(OS_TCB*)&Recipient_TCB,
		(CPU_CHAR*)"Recipient Failed...\n",
		(OS_TASK_PTR) Task_Recipient,
		(void*) NULL,
		(OS_PRIO) TASK_RECIPIENT_PRIO,
		(CPU_STK*) Recipient_Stk,
		(CPU_STK_SIZE) TASK_RECIPIENT_STACK_SIZE,
		(CPU_STK_SIZE) TASK_RECIPIENT_STACK_SIZE,
		(OS_MSG_QTY) 0,
		(OS_TICK) 0,
		(void*) NULL,
		(OS_OPT) OS_OPT_TASK_STK_CLR,
		(OS_ERR*) &err
	);

	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
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
