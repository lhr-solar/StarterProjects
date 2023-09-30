#ifndef MAIL_H
#define MAIL_H

// Specific imports.
#include "os.h"

// General Imports.
# include <stdlib.h>
# include <stdio.h>

/**
 * Use these declarations for
 * your mail challenge in Tests/Test_Mail.c
 */

// Priority Definitions
#define TASK_RECI_PRIO               1
#define TASK_MAIL_PRIO               1

// Stack Sizes
#define DEFAULT_STACK_SIZE                  256
#define WATERMARK_STACK_LIMIT               DEFAULT_STACK_SIZE/2
#define TASK_MAIL_STACK_SIZE                DEFAULT_STACK_SIZE
#define TASK_RECI_STACK_SIZE                DEFAULT_STACK_SIZE

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
extern char mailbox[256];

#endif
