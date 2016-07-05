#include "qubit.h"
#include <stdio.h>

int main() {
	printf("TESTING QUBIT ENTANGLEMENT\n");
	for(int i = 0; i <= 15; i++) {
		int x = i;
		printf("Step 1: %d\n", x);
		qubit *y = entangle(x);
		x = untangle(y);
		printf("Step 2: %d\n", x);
	}
	printf("TEST COMPLETE");
	return 0;
}
