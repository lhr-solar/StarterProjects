#ifndef CAFE_H
#define CAFE_H

#include "os.h"

/**
 * Use these declarations for
 * your cafe challenge in Tests/Test_Cafe.c
 */

// Mailbox semaphore, required by the mailman and recipient tasks
extern OS_SEM MailboxFlag_Sem4;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
extern char mailbox[256];

#endif