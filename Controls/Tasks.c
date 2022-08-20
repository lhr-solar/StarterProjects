#include "Tasks.h"

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
