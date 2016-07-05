#include "qubitll.h"
#include <stdio.h>

int main() {

	// TEST 1
	printf("TESTING QUBIT ENTANGLEMENT\n");

	for(int i = 0; i < 16; i++) {

		int x = i;

		printf("Step 1: %d\n", x);

		qubit *y = entangle(x);
		x = untangle(y);

		printf("Step 2: %d\n", x);

	}

	printf("TEST COMPLETE");

	// TEST 2
	qll *testll = newLL();

	for(int i = 0; i < 16; i++) {

		appLL(testll, entangle(i));

	}

	purgeLL(testll);

	return 0;
}
