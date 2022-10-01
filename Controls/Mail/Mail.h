#ifndef MAIL_H
#define MAIL_H

#include "os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Use these declarations for
 * your mail challenge in Tests/Test_Mail.c
 */

// Function for checking error and printing if not NONE
void checkError(OS_ERR err);

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
extern char mailbox[256];


#endif
