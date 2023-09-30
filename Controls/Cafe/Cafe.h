#ifndef CAFE_H
#define CAFE_H

#include "os.h"
#include <stdio.h>

/**
 * Use these declarations for
 * your cafe challenge in Tests/Test_Cafe.c
 */

// Priority Definitions
#define TASK_CUS1_PRIO               1
#define TASK_CUS2_PRIO               1

// Stack Sizes
#define DEFAULT_STACK_SIZE                  256
#define WATERMARK_STACK_LIMIT               DEFAULT_STACK_SIZE/2
#define TASK_MAIL_STACK_SIZE                DEFAULT_STACK_SIZE
#define TASK_RECI_STACK_SIZE                DEFAULT_STACK_SIZE

// Register mutex, required by the customer tasks
extern OS_MUTEX RegisterOccupied_Mutex;

extern char* menu[4];
extern int costs[4];
extern int revenue; // Business revenue, increased by the purchasing customers.

#endif