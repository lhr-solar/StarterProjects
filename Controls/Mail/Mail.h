#ifndef MAIL_H
#define MAIL_H

#include "os.h"

/**
 * Use these declarations for
 * your mail challenge in Tests/Test_Mail.c
 */

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
extern char mailbox[256];

#endif
