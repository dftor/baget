#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gpiocon_export(int gpio_index) {
	FILE *export_ptr = fopen(GPIO_EXPORT, "w");
	if (export_ptr == NULL) {
		perror("Eport error");
		exit(EXIT_FAILURE);
	}
	fprintf(export_ptr, "%d", gpio_index);
	fclose(export_ptr);
}

void gpiocon_unexport(int gpio_index) {
	FILE *unexport_ptr = fopen(GPIO_UNEXPORT, "w");
	if (unexport_ptr == NULL) {
		perror("Unexport error");
		exit(EXIT_FAILURE);
	}
	fprintf(unexport_ptr, "%d", gpio_index);
	fclose(unexport_ptr);
}

void gpiocon_set_direction(int gpio_index, const char *mode) {
	char direction_path[256];
	sprintf(direction_path,
			"sys/class/gpio/gpio%d/direction",
			gpio_index);
	FILE *direction_ptr = fopen(direction_path, "w");
	if (direction_ptr == NULL) {
		perror("Set direction error");
		exit(EXIT_FAILURE);
	}
	fprintf(direction_ptr, "%s", mode);
	fclose(direction_ptr);
}

void gpiocon_set_value(int gpio_index, int value) {
	char value_path[256];
	sprintf(value_path,
			"sys/class/gpio/gpio%d/value",
			gpio_index);
	FILE *value_ptr = fopen(value_path, "w");
	if (value_ptr == NULL) {
		perror("Set value error");
		exit(EXIT_FAILURE);
	}
	fprintf(value_ptr, "%d", value);
	fclose(value_ptr);
}
