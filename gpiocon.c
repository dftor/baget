#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gpiocon_export(int gpiochip) {
	FILE *export_ptr = fopen(GPIO_EXPORT, "w");
	if (export_ptr == NULL) {
		return -1;
	}
	fprintf(export_ptr, "%d", gpiochip);
	fclose(export_ptr);
	return 0;
}

int gpiocon_unexport(int gpiochip) {
	FILE *unexport_ptr = fopen(GPIO_UNEXPORT, "w");
	if (unexport_ptr == NULL) {
		return -1;
	}
	fprintf(unexport_ptr, "%d", gpiochip);
	fclose(unexport_ptr);
	return 0;
}

int gpiocon_set_direction(int gpiochip, const char *mode) {
	char direction_path[32];
	sprintf(direction_path,
			"/sys/class/gpio/gpio%d/direction",
			gpiochip);
	FILE *direction_ptr = fopen(direction_path, "w");
	if (direction_ptr == NULL) {
		return -1;
	}
	fprintf(direction_ptr, "%s", mode);
	fclose(direction_ptr);
	return 0;
}

int gpiocon_set_value(int gpiochip, int value) {
	char value_path[32];
	sprintf(value_path,
			"/sys/class/gpio/gpio%d/value",
			gpiochip);
	FILE *value_ptr = fopen(value_path, "w");
	if (value_ptr == NULL) {
		return -1;
	}
	fprintf(value_ptr, "%d", value);
	fclose(value_ptr);
	return 0;
}

int gpiocon_get_value(int gpiochip) {
	char value_path[32];
	sprintf(value_path,
			"/sys/class/gpio/gpio%d/value",
			gpiochip);
	FILE *value_ptr = fopen(value_path, "r");
	if (value_ptr == NULL) {
		return -1;
	}
	
	int value = 0;
	fscanf(value_ptr, "%d", &value);
	fclose(value_ptr);
	return value;
}
