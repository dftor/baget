#include "baget.h"

#include <dos.h>

int main() {
	const char *LED_GREEN = "C7";
	const char *LED_YELLOW = "A7";
	const char *LED_RED = "B3";
	
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_YELLOW, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	digitalWrite(LED_GREEN, LOW);
	digitalWrite(LED_YELLOW, LOW);
	digitalWrite(LED_RED, LOW);
	
	for (int i = 0; i < 5; i++) {
		digitalWrite(LED_GREEN, HIGH);
		delay(500);
		digitalWrite(LED_GREEN, LOW);
		
		digitalWrite(LED_YELLOW, HIGH);
		delay(500);
		digitalWrite(LED_YELLOW, LOW);
		
		digitalWrite(LED_RED, HIGH);
		delay(500);
		digitalWrite(LED_RED, LOW);
	}
	
	return 0;
}
