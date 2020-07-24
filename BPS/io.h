#include <stdio.h>
#include <stdbool.h>
#include "config.h"

//simulation for initialization

void currentInit(void);

void tempInit(void);

void voltInit(void);

void contactorInit(void);

//functions to read state of battery
//feel free to make these more complex for testing purposes

int currentRead(void);

int tempRead(void);

int voltRead(void);

//functions to control contactor

void setContactor(bool state);

