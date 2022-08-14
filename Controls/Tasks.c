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

// Mailbox semaphore, required by the mailman and recipient tasks
OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
char mailbox[256] = {'\0'};

// Register mutex, required by the customer tasks
OS_MUTEX RegisterOccupied_Mutex;

char* menu[4] = {"Coffee", "Hot Chocolate", "Pizza", "Donut"}; // Menu (4 items). Feel free to change the menu items.
int costs[4] = {5, 3, 6, 2}; // Costs of the corresponding menu items. Feel free to change these.
int revenue = 0; // Business revenue, increased by the purchasing customers.
