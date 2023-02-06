#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gpiocon_export(int gpiochip) {
	FILE *export_ptr = fopen(GPIO_EXPORT, "w");
	if (export_ptr == NULL) {
		perror("Export error");
		exit(EXIT_FAILURE);
	}
	fprintf(export_ptr, "%d", gpiochip);
	fclose(export_ptr);
}

void gpiocon_unexport(int gpiochip) {
	FILE *unexport_ptr = fopen(GPIO_UNEXPORT, "w");
	if (unexport_ptr == NULL) {
		perror("Unexport error");
		exit(EXIT_FAILURE);
	}
	fprintf(unexport_ptr, "%d", gpiochip);
	fclose(unexport_ptr);
}

void gpiocon_set_direction(int gpiochip, const char *mode) {
	char direction_path[256];
	sprintf(direction_path,
			"sys/class/gpio/gpio%d/direction",
			gpiochip);
	FILE *direction_ptr = fopen(direction_path, "w");
	if (direction_ptr == NULL) {
		perror("Set direction error");
		exit(EXIT_FAILURE);
	}
	fprintf(direction_ptr, "%s", mode);
	fclose(direction_ptr);
}

void gpiocon_set_value(int gpiochip, int value) {
	char value_path[256];
	sprintf(value_path,
			"sys/class/gpio/gpio%d/value",
			gpiochip);
	FILE *value_ptr = fopen(value_path, "w");
	if (value_ptr == NULL) {
		perror("Set value error");
		exit(EXIT_FAILURE);
	}
	fprintf(value_ptr, "%d", value);
	fclose(value_ptr);
}
