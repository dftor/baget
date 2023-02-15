#include "button.h"

int main() {
	Button left = init("F1", "LEFT", 10);
	
	printStateMessage(&left);
	
	clear(&left);

	
	return 0;
}
