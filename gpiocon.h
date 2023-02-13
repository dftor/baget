#ifndef GPIOCON_H
#define GPIOCON_H

#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"

int gpiocon_export(int gpiochip);
int gpiocon_unexport(int gpiochip);
int gpiocon_set_direction(int gpiochip, const char *mode);
int gpiocon_set_value(int gpiochip, int value);
int gpiocon_get_value(int gpiochip);

#endif
