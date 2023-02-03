#ifndef GPIOCON_H
#define GPIOCON_H

const char GPIO_ROOT[] = "sys/class/gpio";
const char GPIO_EXPORT[] = "sys/class/gpio/export";
const char GPIO_UNEXPORT[] = "sys/class/gpio/unexport";

bool LOW = 0;
bool HIGH = 1;

bool OUTPUT = 1;
bool INPUT = 0;

void pinMode(uint8_t pin, bool mode);

#endif
