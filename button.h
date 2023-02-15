#ifndef BUTTON_H
#define BUTTON_H

typedef enum {
	RELEASED = 0,
	PRESSED = 1
} State;

typedef struct {
	int isNewState;
	State state;
	const char *pin;
	const char *name;
	unsigned int bounceTime;
} Button;

void printStateMessage(Button *button);
State readState(Button *button);
void checkState(Button *button);
Button init(const char *pin, const char *name, unsigned int bounceTime);
void clear(Button *button);

#endif
