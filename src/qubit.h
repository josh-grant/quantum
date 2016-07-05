// Author: Josh Grant 2016
//
// Data structure and functionality for entangled qubits

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structs
// * qubit

struct Qubit {
	bool q_0;
	bool q_1;
	bool q_2;
	bool q_3;
};

typedef struct Qubit qubit;

// Functions
// * qubit *entangle(int x)
// * int untangle(qubit *x)

qubit *entangle(int x) {

	// This function takes an int (0-15) and parses it into a base 16 entangled qubit

	// BOUNDS CHECKING
	if(x < 0 || x > 15) {
		printf("ARGERROR: INTEGER \"%d\" OUT OF BOUNDS: MUST BE BETWEEN 0 AND 15\n", x);
		exit(-1);
	}
	// POINTER INITIALISATION
	qubit *newQ = malloc(sizeof(qubit));

	if(newQ == NULL) {
		printf("MEMERROR: POINTER REFERENCES NULL MEMORY ADDRESS\n");
		exit(-1);
	}
	// INT (0-15) - > QUBIT PARSING
	if(x % 2 != 0) {
		newQ->q_0 = true;
	} else {
		newQ->q_0 = false;
	}
	if(x/2 % 2 != 0) {
		newQ->q_1 = true;
	} else {
		newQ->q_1 = false;
	}
	if(x/4 % 2 != 0) {
		newQ->q_2 = true;
	} else {
		newQ->q_2 = false;
	}
	if(x/8 % 2 != 0) {
		newQ->q_3 = true;
	} else {
		newQ->q_3 = false;
	}

	return newQ;
}

int untangle(qubit *x) {

	// This function takes a base 16 entangled qubit and parses it to an int

	int newInt = 0;

	if(x->q_0 == true) {
		newInt += 1;
	}
	if(x->q_1 == true) {
		newInt += 2;
	}
	if(x->q_2 == true) {
		newInt += 4;
	}
	if(x->q_3 == true) {
		newInt += 8;
	}

	free(x);

	return newInt;
}
