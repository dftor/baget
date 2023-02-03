#ifndef GPIOCON_H
#define GPIOCON_H

#define GPIO_ROOT "sys/class/gpio"
#define GPIO_EXPORT "sys/class/gpio/export"
#define GPIO_UNEXPORT "sys/class/gpio/unexport"

#define LOW 0
#define HIGH 1

#define INPUT "in"
#define OUTPUT "out"

int gpiocon_export(int gpio_index);
int gpiocon_unexport(int gpio_index);
int gpiocon_set_direction(int gpio_index, const char *mode);
int gpiocon_set_value(int gpio_index);

#endif
