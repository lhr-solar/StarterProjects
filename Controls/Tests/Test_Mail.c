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
	OSSemCreate(&MailboxFlag_Sem4, 
				"mailboxSemaphore",
				1, 
				&err);

	OS_TCB MailMan_TCB;
	OS_TCB Recipient_TCB;

	CPU_STK MailmanStk[256];
	CPU_STK RecipientStk[256];


	// Initialize both tasks here


	OSTaskCreate
	(
        (OS_TCB*)     &MailMan_TCB,
        (CPU_CHAR*)   "MailMan",
        (OS_TASK_PTR) Task_Mailman,
        (void*)       NULL,
        (OS_PRIO)     2,
        (CPU_STK*)    MailmanStk,
        (CPU_STK_SIZE)128/10,
        (CPU_STK_SIZE)256,
        (OS_MSG_QTY)  0,
        (OS_TICK)     0,
        (void*)       NULL,
        (OS_OPT)      (OS_OPT_TASK_STK_CLR),
        (OS_ERR*)     &err
    );

	OSTaskCreate
	(
        (OS_TCB*)     &Recipient_TCB,
        (CPU_CHAR*)   "Recipient",
        (OS_TASK_PTR) Task_Recipient,
        (void*)       NULL,
        (OS_PRIO)     2,
        (CPU_STK*)    RecipientStk,
        (CPU_STK_SIZE)128/10,
        (CPU_STK_SIZE)256,
        (OS_MSG_QTY)  0,
        (OS_TICK)     0,
        (void*)       NULL,
        (OS_OPT)      (OS_OPT_TASK_STK_CLR),
        (OS_ERR*)     &err
    );
	

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
