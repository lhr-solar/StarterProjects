#include "config.h"
#include "io.h"

int main(void){
	//TODO: initialization here
	currentInit();
	tempInit();
	voltInit();
	contactorInit();
	while(1){
		//TODO: main loop here
		currentRead();
		voltRead();
		tempRead();

		if (current > MAX_CURRENT || voltage > MAX_VOLTAGE || voltage < MIN_VOLTAGE || temperature > MAX_TEMP) {
			setContactor(false);
		}
		else {
			setContactor(true); //if conditions are acceptable, contactor turns on again
		}
	}
	return 0;
}

