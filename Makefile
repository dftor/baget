TARGET = brk
CC = gcc

$(TARGET) : main.o gpiocon.o baget.o
	$(CC) main.o gpiocon.o baget.o -o $(TARGET)
	
main.o : main.c
	$(CC) -c main.c -o main.o
	
gpiocon.o : gpiocon.c
	$(CC) -c gpiocon.c -o gpiocon.o
	
baget.o : baget.c
	$(CC) -c baget.c -o baget.o
	
clean :
	rm $(TARGET) *.o
	
