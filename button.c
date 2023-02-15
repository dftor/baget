#include "button.h"
#include "baget.h"

#include <stdio.h>

void printStateMessage(Button *button) {
	char message[64];
	const char *state = button->state == RELEASED 
	                  ? "Released" : "Pressed";
	sprintf(message, "%s: %s", button->name, state);
	printf("%s\n", message);
}

State readState(Button *button) {
	int digitalSignal = digitalRead(button->pin);
	return (State)digitalSignal;
}

void checkState(Button *button) {
	State state = readState(button);
	if (state != button->state) {
		delay(button->bounceTime);
		state = readState(button);
		if (state != button->state) {
			button->state = state;
			button->isNewState = 1;
		}
	} else {
		button->isNewState = 0;
	}
}

Button init(const char *pin, const char *name,
            unsigned int bounceTime) {
	Button button = {
		.isNewState = 0,
		.state = RELEASED,
		.pin = pin,
		.name = name,
		.bounceTime = bounceTime
	};
	
	pinMode(pin, INPUT);
	return button;
}

void clear(Button *button) {
	button->isNewState = 0;
	button->state = RELEASED;
	button->name = NULL;
	button->bounceTime = 0;
	
	pinFree(button->pin);
	button->pin = NULL;
}
