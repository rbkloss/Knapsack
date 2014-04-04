/*
 * Knapsack.h
 *
 *  Created on: Nov 22, 2013
 *      Author: ricardo
 */

#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct KnapSackElement {
	int weight;
	int value;
	int ID;
} KnapsackElement;

typedef struct Knapsack {
	int capacity;
	int value;
	ListHead* elements;
} Knapsack;

void instantiateKnapsackElement(KnapsackElement** new_knapsack_el, int ID,
		int value, int weight);
void freeknapsackElement(KnapsackElement** knapsack_el);

void instantiateKnapsack(Knapsack** new_knapsack, int cap) ;
void freeKnapsack(Knapsack** knapsack);

void solveKnapsackProblem(KnapsackElement* elements[], int elements_len,
		Knapsack* solved_knapsacks[], const int MAX_CAP);

ListNode* searchKnapsackElement(Knapsack* knapsack, int ID);

Knapsack* copyKnapsack(Knapsack* knapsack);

void addElement(Knapsack* knapsack, KnapsackElement* element);

void printKnapsack(Knapsack* knapsack);

#endif /* KNAPSACK_H_ */
