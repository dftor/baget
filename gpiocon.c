#include "gpiocon.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gpiocon_export(int gpio_index) {
	FILE *export = fopen(EXPORT, "w");
	if (export == NULL) {
		return 1;
	}
	fprintf(export, "%d", gpio_index);
	fclose(export);
	return 0;
}

int gpiocon_export(int gpio_index) {
	FILE *unexport = fopen(UNEXPORT, "w");
	if (unexport == NULL) {
		return 1;
	}
	fprintf(unexport, "%d", gpio_index);
	fclose(unexport);
	return 0;
}

int gpiocon_set_direction(int gpio_index, const char *mode) {
	
	
}
