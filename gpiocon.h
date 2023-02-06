#ifndef GPIOCON_H
#define GPIOCON_H

#define GPIO_ROOT "sys/class/gpio"
#define GPIO_EXPORT "sys/class/gpio/export"
#define GPIO_UNEXPORT "sys/class/gpio/unexport"

void gpiocon_export(int gpio_index);
void gpiocon_unexport(int gpio_index);
void gpiocon_set_direction(int gpio_index, const char *mode);
void gpiocon_set_value(int gpio_index, int value);

#endif
