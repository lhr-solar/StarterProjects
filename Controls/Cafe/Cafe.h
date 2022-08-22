#ifndef CAFE_H
#define CAFE_H

#include "os.h"

/**
 * Use these declarations for
 * your cafe challenge in Tests/Test_Cafe.c
 */

// Register mutex, required by the customer tasks
extern OS_MUTEX RegisterOccupied_Mutex;

// Mailbox contents (allocated as 256 characters long, initialized to be empty)
extern char mailbox[256];

#endif