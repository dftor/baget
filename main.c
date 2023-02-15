#include "button.h"

#include <stdio.h>
#include <time.h>

int main() {
	Button left = init("D2", "LEFT", 10);
	Button middle = init("B3", "MIDDLE", 10);
	Button right = init("C6", "RIGHT", 10);
	
	printf("Button status tracking has started!\n");
	
	int trackingTime = 0;
	printf("Input time of tracking as seconds:\n");
	scanf("%d", &trackingTime);
	
	time_t begin = time(NULL);
	time_t end = begin;
	
	while (end - begin < trackingTime) {
		end = time(NULL);
		
		checkState(&left);
		if (left.isNewState == 1) printStateMessage(&left);
		
		checkState(&middle);
		if (middle.isNewState == 1) printStateMessage(&middle);
		
		checkState(&right);
		if (right.isNewState == 1) printStateMessage(&right);
	}
	
	clear(&left);
	clear(&middle);
	clear(&right);
	
	printf("The program terminated successfully.\n");
	
	return 0;
}
