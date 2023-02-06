#include "baget.h"
#include "gpiocon.c"

int pin_to_gpiochip(const char *pin) {
	int line = 464 + ('F' - pin[0]) * 8;
	int number = pin[2] - '0';
	int gpiochip = line + number;
	return gpiochip;
}

void pinMode(const char *pin, const char *mode) {
	int gpiochip = pin_to_gpiochip(pin);
	gpiocon_export(gpiochip);
	gpiocon_set_direction(gpiochip, mode);
}
