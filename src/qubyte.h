// Author: Joshua Grant
//
// Data Structure and functionality for qubyte level operation

#include "qubitll.h"

// Structs
// * qubyte

struct Qubyte {

	qubit *arr[8];

};

typedef struct Qubyte qubyte;

// Functionality
// * qubyte *newqb(qubit *arr[8])
// * void purgeqb(qubyte * qb)

qubyte *newqb(int *arr[8]) {

	// Returns new qubyte with qubit values of passed qubit array

	// POINTER INITIALISATION
	qubyte *newqb = malloc(sizeof(qubyte));

	if(newqb == NULL) {

		printf("MEMERROR: POINTER REFERENCES NULL MEMORY ADDRESS\n");
		exit(-1);
		
	}

	// QUBIT ARRAY INITIALISATION

	for(int i = 0; i < 8; i++) {

		mutbit(newqb->arr[i]->qubit, arr[i])

	}

	return newqb;

}

void purgeqb(qubyte *qb) {

	// This function deallocates all memory allocated to qubyte
}