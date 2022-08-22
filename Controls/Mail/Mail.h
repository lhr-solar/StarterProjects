#ifndef MAIL_H
#define MAIL_H

#include "os.h"

/**
 * Use these declarations for
 * your mail challenge in Tests/Test_Mail.c
 */

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

extern char* menu[4];
extern int costs[4];
extern int revenue; // Business revenue, increased by the purchasing customers.

#endif
