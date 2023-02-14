#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pin_to_gpiochip(const char *pin) {
	int line = 464 + ('F' - pin[0]) * 8;
	int number = pin[1] - '0';
	int gpiochip = line + number;
	return gpiochip;
}

void print_error_termination_message() {
	printf("The program terminated with an error.\n");
}

void pinMode(const char *pin, const char *mode) {
	int gpiochip = pin_to_gpiochip(pin);
	int export_result = gpiocon_export(gpiochip);
	if (export_result == -1) {
		printf("EXPORT_ERROR: Unable to export %s pin!\n",
		       pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
	
	int direction_result = gpiocon_set_direction(gpiochip, mode);
	if (direction_result == -1) {
		printf("SET_DIRECTION_ERROR: Unable to set %s direction of %s pin!\n",
			   mode, pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
}

void digitalWrite(const char *pin, int value) {
	int gpiochip = pin_to_gpiochip(pin);
	int set_value_result = gpiocon_set_value(gpiochip, value);
	if (set_value_result == -1) {
		printf("SET_VALUE_ERROR: Unable to set %d of %s pin!\n",
			   value, pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
}

int digitalRead(const char *pin) {
	int gpiochip = pin_to_gpiochip(pin);
	int get_value_result = gpiocon_get_value(gpiochip);
	if (get_value_result == -1) {
		printf("GET_VALUE_ERROR: Unable to get value of %s pin!\n",
		       pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
	return get_value_result;
}

void pinFree(const char *pin) {
	int gpiochip = pin_to_gpiochip(pin);
	int unexport_result = gpiocon_unexport(gpiochip);
	if (unexport_result == -1) {
		printf("UNEXPORT_ERROR: Unable to unexport %s pin!\n",
			   pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
}

void delay(unsigned int delayTime) {
	unsigned int usecs = 1000 * delayTime;
	usleep(usecs);
}
