#ifndef TASKS_H
#define TASKS_H

#include "os.h"

/**
 * Use these declarations and macros to 
 * create your tasks in main.c
 */

// Task prototypes
void Task_Mailman(void* p_arg);
void Task_Recipient(void* p_arg);
void Task_Customer_1(void* p_arg);
void Task_Customer_2(void* p_arg);

// Priorities
#define TASK_MAILMAN_PRIO 1
#define TASK_RECIPIENT_PRIO 2
#define TASK_CUST_1_PRIO 3
#define TASK_CUST_2_PRIO 4

// Stack sizes
#define TASK_MAILMAN_STACK_SIZE 256
#define TASK_RECIPIENT_STACK_SIZE 256
#define TASK_CUST_1_STACK_SIZE 256
#define TASK_CUST_2_STACK_SIZE 256
#define TASK_STACK_LIMIT 128

// Task Control Blocks (TCBs) contain information relevant to a specific thread, including stack pointers, flags, etc.
extern OS_TCB Mailman_TCB;
extern OS_TCB Recipient_TCB;
extern OS_TCB Customer_1_TCB;
extern OS_TCB Customer_2_TCB;

// Stacks are where your function calls in a particular task will access and modify memory (local variables and parameters for functions will be stored in these stacks)
extern CPU_STK Mailman_Stk[TASK_MAILMAN_STACK_SIZE];
extern CPU_STK Recipient_Stk[TASK_RECIPIENT_STACK_SIZE];
extern CPU_STK Customer_1_Stk[TASK_CUST_1_STACK_SIZE];
extern CPU_STK Customer_2_Stk[TASK_CUST_2_STACK_SIZE];

#endif