#ifndef BUTTON_H
#define BUTTON_H

#include "baget.h"

typedef enum {
	RELEASED = 0,
	PRESSED = 1
} State;

typedef struct {
	int isNewState = 0;
	State state = RELEASED;
	const char *pin = NULL;
	const char *name = NULL;
	unsigned int bounceTime = 0;
} Button;

void printStateMessage(Button *button);
State readState(Buttin *button);
void checkState(Button *button);

#endif
