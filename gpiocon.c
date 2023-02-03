#define GPIO_ROOT "sys/class/gpio"
#define GPIO_EXPORT "sys/class/gpio/export"
#define GPIO_UNEXPORT "sys/class/gpio/unexport"

#define LOW 0
#define HIGH 1
#define INPUT "in"
#define OUTPUT "out"

#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gpiocon_export(int gpio_index) {
	FILE *export_stream = fopen(GPIO_EXPORT, "w");
	if (export_stream == NULL) {
		return 1;
	}
	fprintf(export_stream, "%d", gpio_index);
	fclose(export_stream);
	return 0;
}

int gpiocon_unexport(int gpio_index) {
	FILE *unexport_stream = fopen(GPIO_UNEXPORT, "w");
	if (unexport_stream == NULL) {
		return 1;
	}
	fprintf(unexport_stream, "%d", gpio_index);
	fclose(unexport_stream);
	return 0;
}

int gpiocon_set_direction(int gpio_index, const char *mode) {
	char direction_path[256];
	sprintf(direction_path,
			"sys/class/gpio/gpio%d/direction",
			gpio_index);
	FILE *direction_stream = fopen(direction_path, "w");
	if (direction_stream == NULL) {
		return 1;
	}
	fprintf(direction_stream, "%s", mode);
	fclose(direction_stream);
	return 0;
}

int gpiocon_set_value(int gpio_index, int value) {
	char value_path[256];
	sprintf(value_path,
			"sys/class/gpio/gpio%d/value",
			gpio_index);
	FILE *value_stream = fopen(value_path, "w");
	if (value_stream == NULL) {
		return 1;
	}
	fprintf(value_stream, "%d", value);
	fclose(value_stream);
	return 0;
}
