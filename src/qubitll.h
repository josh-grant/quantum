// Author: Josh Grant 2016
//
// Data Structure and functionality for linked list of qubits

#include "qubit.h"

// Structs
// * qubitll

struct QubitNode {
	qubit *value;
	struct QubitNode *next;
};

struct QubitLL {
	struct QubitNode *head;
	int len;
};

typedef struct QubitNode qnode;
typedef struct QubitLL qll;

// Functions
// * qnode *newNode(qubit *value)
// * qll *newll(void:null)
// * qnode travll(int index)
// * void appll(qll *ll, qubit *value)
// * void purgell(qll *ll)

qnode *newNode(qubit *value) {

	// This function returns a qnode with passed qubit value and a null next pointer

	// POINTER INITIALISATION
	qnode *node = malloc(sizeof(qnode));

	if(node == NULL) {

		printf("MEMERROR: POINTER REFERENCES NULL MEMORY ADDRESS\n");
		exit(-1);

	}

	// FIELD INITIALISATION
	node->value = value;
	node->next = NULL;

	return node;
}

qll *newll() {

	// This function returns an empty qll with len 0;

	// POINTER INITIALISATION
	qll *ll = malloc(sizeof(qll));

	if(ll == NULL) {

		printf("MEMERROR: POINTER REFERENCES NULL MEMORY ADDRESS\n");
		exit(-1);

	}

	// FIELD INITIALISATION
	ll->head = NULL;
	ll->len = 0;

	return ll;
}

qnode *travll(qll *ll, int index) {

	// This function returns the nth node in the LL where n = index

	// BOUNDS CHECKING
	if(ll->head == NULL) {

		printf("DATERR: DATA STRUCTURE EMPTY");
		exit(-1);

	}
	if(ll->len <= index) {

		printf("DATERR: INDEX %d OUT OF BOUNDS", index);
		exit(-1);

	}

	// DATA STRUCTURE TRAVERSION
	qnode *curr = ll->head;

	for(int i = 0; i < index; i++) {

		curr = curr->next;

	}

	return curr;
}

void appll(qll *ll, qubit *value) {

	// This function appends a node of passed value to the end of the passed qll

	// APPEND TO DATA STRUCTURE
	if(ll->len > 0) {

		qnode *tail = travll(ll, ll->len);
		qnode *node = newNode(value);

		tail->next = node;

	} else {

		ll->head = newNode(value);

	}

	// INCREMENT LENGTH
	ll->len++;
}

void purgell(qll *ll) {

	// This function deallocates all memory allocated to the passed qll

	// PURGE qll
	if(ll->len > 0) {

		qnode *curr = ll->head;
		qnode *next = NULL;

		for(int i = 0; i < ll->len; i++) {
			next = curr->next;
			free(curr);
			curr = next;
		}

		free(ll);

	} else {

		free(ll);

	}
}
