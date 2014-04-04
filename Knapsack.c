/*
 * Knapsack.c
 *
 *  Created on: Nov 22, 2013
 *      Author: ricardo
 */
#include "Knapsack.h"
#define quantity aux

void solveKnapsackProblem(KnapsackElement* elements[], int elements_len,
		Knapsack* solved_knapsacks[], const int MAX_CAP) {

	int capacity = 0;
	int current_value = 0;
	//K(capacity) = K(capacity - w_i) +v_i :
	for (capacity = 0; capacity < MAX_CAP; capacity++) {
		int current_max_value = 0;
		int knapsack_to_add = 0;
		KnapsackElement* element_chosen = NULL;
		int element_it = 0;
		for (element_it = 0; element_it < elements_len; element_it++) {
			KnapsackElement* element = NULL;
			element = elements[element_it];
			int current_capacity = 0;
			current_capacity = capacity - element->weight;
			if (current_capacity < 0) {
				continue;
			}
			current_value = 0;

			if (solved_knapsacks[current_capacity] == NULL) {
				current_value = element->value;
			} else {
				current_value = solved_knapsacks[current_capacity]->value
						+ element->value;
			}

			if (current_value > current_max_value) {
				current_max_value = current_value;
				element_chosen = element;
				knapsack_to_add = current_capacity;
			}
		}
		//create a copy of chosen knapsack and add it the chosen element
		Knapsack* new_knapsack = NULL;
		if (element_chosen != NULL) {
			printf("K(%d) = K(%d - %d) + %d\n\n", capacity, capacity,
					element_chosen->weight, element_chosen->value);
		} else {
			printf("K(%d) = 0\n\n", capacity);
		}
		if (solved_knapsacks[knapsack_to_add] == NULL) {
			instantiateKnapsack(&new_knapsack, capacity);
		} else {
			new_knapsack = copyKnapsack(solved_knapsacks[knapsack_to_add]);
			new_knapsack->capacity = capacity;
		}
		if (element_chosen != NULL) {
			addElement(new_knapsack, element_chosen);
		}
		solved_knapsacks[capacity] = new_knapsack;
	}
}

void instantiateKnapsackElement(KnapsackElement** new_knapsack_el, int ID,
		int value, int weight) {
	(*new_knapsack_el) = malloc(sizeof(KnapsackElement));
	KnapsackElement* el = (*new_knapsack_el);
	el->ID = ID;
	el->value = value;
	el->weight = weight;
}

void freeknapsackElement(KnapsackElement** knapsack_el) {
	free((*knapsack_el));
	(*knapsack_el) = NULL;
}

void instantiateKnapsack(Knapsack** new_knapsack, int cap) {
	if ((*new_knapsack == NULL)) {
		freeKnapsack(new_knapsack);
	}
	(*new_knapsack) = malloc(sizeof(Knapsack));
	Knapsack* knapsack = (*new_knapsack);
	knapsack->capacity = cap;
	knapsack->elements = NULL;
	knapsack->value = 0;
}

ListNode* searchKnapsackElement(Knapsack* knapsack, int ID) {
	ListHead* head = NULL;
	head = knapsack->elements;
	if (head == NULL) {
		return NULL;
	}
	ListNode* node = head->head;
	if (node == NULL) {
		return NULL;
	}

	while (node->next != NULL) {
		KnapsackElement* element = (KnapsackElement*) node->element;
		if (element->ID == ID) {
			return node;
		}
		node = node->next;
	}
	KnapsackElement* element = (KnapsackElement*) node->element;
	if (element->ID == ID) {
		return node;
	}

	return NULL;
}

Knapsack* copyKnapsack(Knapsack* knapsack) {
	if (knapsack == NULL)
		return NULL;
	Knapsack* copy = NULL;
	copy = malloc(sizeof(Knapsack));

	copy->capacity = knapsack->capacity;
	copy->value = knapsack->value;
	copy->elements = copyList(knapsack->elements);

	return copy;
}

void addElement(Knapsack* knapsack, KnapsackElement* new_element) {
	ListNode* node = NULL;

	node = searchKnapsackElement(knapsack, new_element->ID);
	if (node != NULL) { //if node exists in the Knapsack Element list
		node->quantity++;
		knapsack->value += new_element->value;
	} else {
		if (knapsack->elements == NULL) {
			initListHead(&(knapsack->elements));
		}
		//create new Node:
		initListNode(&node);

		node->element = new_element;
		node->quantity = 1;
		addNode(knapsack->elements, node);
	}

	knapsack->value += new_element->value;
}

void freeKnapsack(Knapsack** knapsack) { //the elements are freed elsewhere
	if ((*knapsack) == NULL) {
		return;
	}
	Knapsack* knap = (*knapsack);
	knap->elements = NULL;
	free(knap);
	knap = NULL;
}

void printKnapsack(Knapsack* knapsack) {
	if (knapsack == NULL) {
		return;
	}
	printf("KNAPSACK:\ncapacity [%d], value [%d]\n", knapsack->capacity,
			knapsack->value);
	printf(" items: \n\t");
	printList(knapsack->elements);
	printf("\n\n");
}

void printElement(void *element) { //list abstract Method
	KnapsackElement* el = (KnapsackElement*) element;

	printf("ELEMENT: ID[%d],Value[%d],Weight[%d]\n", el->ID, el->value,
			el->weight);
}
