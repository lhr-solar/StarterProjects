MotorController: MotorController.o main.o
	gcc MotorController.o main.o -o MotorController

MotorController.o: MotorController.c 
	gcc -std=c99 -c MotorController.c 

main.o: main.c
	gcc -std=c99 -c main.c 

clean:
	rm *.o MotorController


