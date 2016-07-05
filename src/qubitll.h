// Author: Josh Grant 2016
//
// Data Structure and functionality for linked list of qubits

#include "qubit.h"

// Structs
// * qubitll

struct QubitNode {
	qubit *value;
	struct QubitNode *tail;
};

struct QubitLL {
	qubit *head;
	int len;
};

typedef struct QubitNode qnode;
typedef struct QubitLL qll;

// Functions
// * qnode *newNode(qubit *value)

qnode *newNode(qubit *value) {
	// POINTER INITIALISATION
	qnode *node = malloc(sizeof(qnode));
	if(node == NULL) {
		printf("MEMERROR: POINTER REFERENCES NULL MEMORY ADDRESS\n");
		exit(-1);
	}
}