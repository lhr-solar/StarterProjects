#include "os.h"
#include "../Tasks.h"
#include "../Mail/Mail.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Mailman and Recipient tasks here.
 */

// TCB
OS_TCB MailTCB;
OS_TCB ReciTCB;

// Stack
CPU_STK MailStk[DEFAULT_STACK_SIZE];
CPU_STK ReciStk[DEFAULT_STACK_SIZE];

 // Mailbox semaphore, required by the mailman and recipient tasks
OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

int main(void){
	OS_ERR err;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();
	
	// Create any semaphores/mutexes and initialize any global variables here
	OSSemCreate(&MailboxFlag_Sem4, "Mail Flag", 0, &err);
    srand(time(NULL));  // random number generator

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (mail-sem4): %d\n", err);

	// Initialize both tasks here
	OSTaskCreate(
        (OS_TCB*)&MailTCB,
        (CPU_CHAR*)"Mailman",
        (OS_TASK_PTR)Task_Mailman,
        (void*)NULL,
        (OS_PRIO)TASK_MAIL_PRIO,
        (CPU_STK*)MailStk,
        (CPU_STK_SIZE)WATERMARK_STACK_LIMIT,
        (CPU_STK_SIZE)TASK_MAIL_STACK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)NULL,
        (OS_OPT)(OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err
    );

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (mailman-task): %d\n", err);

	OSTaskCreate(
        (OS_TCB*)&ReciTCB,
        (CPU_CHAR*)"Deposit",
        (OS_TASK_PTR)Task_Recipient,
        (void*)NULL,
        (OS_PRIO)TASK_RECI_PRIO,
        (CPU_STK*)ReciStk,
        (CPU_STK_SIZE)WATERMARK_STACK_LIMIT,
        (CPU_STK_SIZE)TASK_RECI_STACK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)NULL,
        (OS_OPT)(OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err
    );

    // If no error, OS_ERR_NONE = 0
	if (err)
		printf("Error code (recipient-task): %d\n", err);

	OSStart(&err);	// Start the OS

    if (err)
		printf("Error code (OSStart): %d\n", err);

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
