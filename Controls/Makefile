CC=gcc
CFLAGS=-I.
DEPS = MotorController.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

starterProj: main.o MotorController.o 
	$(CC) -o starterProj main.o MotorController.o 