#include "button.h"

void printStateMessage(Button *button) {
	char message[64];
	const char *state = button.state == RELEASED 
	                  ? "Released" : "Pressed";
	sprintf(message, "%s: %s", button.name, state);
	printf("%s\n", message);
}

State readState(Buttin *button) {
	int digitalSignal = digitalRead(button.pin);
	return (State)digitalSignal;
}

void checkState(Button *button) {
	State state = readState(button);
	if (state != button.state) {
		delay(button.bounceTime);
		state = readState(button);
		if (state != button.state) {
			button.state = state;
			button.isNewState = 1;
		}
	} else {
		button.isNewState = 0;
	}
}
