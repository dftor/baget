

BagetProject : main.o gpiocon.o baget.o
	gcc main.o gpiocon.o baget.o -o BagetProject
	
main.o : main.c
	gcc -c main.c -o main.o
	
gpiocon.o : gpiocon.c
	gcc -c gpiocon.c -o gpiocon.o
	
baget.o : baget.c
	gcc -c baget.c -o baget.o
	
