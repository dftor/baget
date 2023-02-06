#ifndef BAGET_H
#define BAGET_H

#define LOW 0
#define HIGH 1
#define INPUT "in"
#define OUTPUT "out"

int pin_to_gpiochip(const char *pin);

void pinMode(const char *pin, const char *mode);
void digitalWrite(const char *pin, int value);
int digitalRead(const char *pin);

#endif
