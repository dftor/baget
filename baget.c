#include "gpiocon.h"

int pin_to_gpiochip(const char *pin) {
	int line = 464 + ('F' - pin[0]) * 8;
	int number = pin[1] - '0';
	int gpiochip = line + number;
	return gpiochip;
}

void print_error_termination_message() {
	printf("The program terminated with an error\n");
}

void pinMode(const char *pin, const char *mode) {
	int gpiochip = pin_to_gpiochip(pin);
	int export_returned = gpiocon_export(gpiochip);
	if (export_returned == -1) {
		printf("Export error: unable to export %s pin!\n", pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
	
	int direction_returned = gpiocon_set_direction(gpiochip, mode);
	if (direction_returned == -1) {
		printf("Set direction error: unable to set %s direction of %s pin!\n", 
			   mode, pin);
		print_error_termination_message();
		exit(EXIT_FAILURE);
	}
}
