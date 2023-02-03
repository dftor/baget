#ifndef GPIOCON_H
#define GPIOCON_H

int gpiocon_export(int gpio_index);
int gpiocon_unexport(int gpio_index);
int gpiocon_set_direction(int gpio_index, const char *mode);
int gpiocon_set_value(int gpio_index, int value);


#endif
