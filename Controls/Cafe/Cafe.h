#ifndef CAFE_H
#define CAFE_H

#include "os.h"

/**
 * Use these declarations for
 * your cafe challenge in Tests/Test_Cafe.c
 */

// Register mutex, required by the customer tasks
extern OS_MUTEX RegisterOccupied_Mutex;

extern char* menu[4];
extern int costs[4];
extern int revenue; // Business revenue, increased by the purchasing customers.

#endif