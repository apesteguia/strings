all: remove str main clear

remove:
	rm main
clear: 
	rm -f *.o
	

main:
	gcc main.c str.o -Wall -o main

str: str.c str.h
	gcc -c str.c -Wall
