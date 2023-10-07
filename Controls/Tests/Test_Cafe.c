#include "os.h"
#include "../Tasks.h"
#include "../Cafe/Cafe.h"
#include <stdio.h>

/**
 * Create and test the functionality of the Customer1 and Customer2 tasks here.
 */

 // Register mutex, required by the customer tasks
OS_MUTEX RegisterOccupied_Mutex;

char* menu[4] = {"Coffee", "Hot Chocolate", "Pizza", "Donut"}; // Menu (4 items). Feel free to change the menu items.
int costs[4] = {5, 3, 6, 2}; // Costs of the corresponding menu items. Feel free to change these.
int revenue = 0; // Business revenue, increased by the purchasing customers.

int main(void){
	OS_ERR err;

	OSInit(&err);	// Initialize the OS
	OS_CPU_SysTickInit();

	// Create any semaphores/mutexes and initialize any global variables here
	OSMutexCreate(&RegisterOccupied_Mutex, "Register mutex", &err);

	// Initialize both tasks here
	

	OSStart(&err);	// Start the OS

	printf("=========\nCafe Test File\n=========\n");

	if(err != OS_ERR_NONE){
		printf("Error Code:%d\n", err);
		return 0;
	}
	else{
		printf("Success! Running simulator...\n");
	}

	while(1){}	// Infinite loop
	return 0;
}
