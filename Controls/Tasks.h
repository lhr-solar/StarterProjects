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

// TCBs
extern OS_TCB Mailman_TCB;
extern OS_TCB Recipient_TCB;
extern OS_TCB Customer_1_TCB;
extern OS_TCB Customer_2_TCB;

// Stacks
extern CPU_STK Mailman_Stk[TASK_MAILMAN_STACK_SIZE];
extern CPU_STK Recipient_Stk[TASK_RECIPIENT_STACK_SIZE];
extern CPU_STK Customer_1_Stk[TASK_CUST_1_STACK_SIZE];
extern CPU_STK Customer_2_Stk[TASK_CUST_2_STACK_SIZE];

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

// Register mutex, required by the customer tasks
extern OS_MUTEX RegisterOccupied_Mutex;

char* menu[4] = {"Coffee", "Hot Chocolate", "Pizza", "Donut"}; // Menu (4 items). Feel free to change the menu items.
int costs[4] = {5, 3, 6, 2}; // Costs of the corresponding menu items. Feel free to change these.
int revenue = 0; // Business revenue, increased by the purchasing customers.

#endif