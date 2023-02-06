#pragma once
#ifndef GPIOCON_H
#define GPIOCON_H

#define GPIO_EXPORT "/sys/class/gpio/export"
#define GPIO_UNEXPORT "/sys/class/gpio/unexport"

void gpiocon_export(int gpiochip);
void gpiocon_unexport(int gpiochip);
void gpiocon_set_direction(int gpiochip, const char *mode);
void gpiocon_set_value(int gpiochip, int value);

#endif
