#include "button.h"

int main() {
	Button left = {
		.isNewState = 0,
		.state = RELEASED,
		.pin = "F1",
		.name = "LEFT",
		.bounceTime = 10
	};
	
	printStateMessage(&left);
	
	return 0;
}
