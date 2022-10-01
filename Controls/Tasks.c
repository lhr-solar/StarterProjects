#include "Tasks.h"
#include <stdio.h>

// TCBs
OS_TCB Mailman_TCB;
OS_TCB Recipient_TCB;
OS_TCB Customer_1_TCB;
OS_TCB Customer_2_TCB;

// Stacks
CPU_STK Mailman_Stk[TASK_MAILMAN_STACK_SIZE];
CPU_STK Recipient_Stk[TASK_RECIPIENT_STACK_SIZE];
CPU_STK Customer_1_Stk[TASK_CUST_1_STACK_SIZE];
CPU_STK Customer_2_Stk[TASK_CUST_2_STACK_SIZE];

// Function for printing errors. To be used in other programs
void checkError (OS_ERR err)
{
    if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
	}
}
