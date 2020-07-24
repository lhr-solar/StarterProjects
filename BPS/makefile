#type "make" to build the project

BPS: main.o io.o
	gcc -o BPS main.o io.o
main.o: main.c config.h io.h 
	gcc -c main.c
io.o: config.h io.h
	gcc -c io.c

