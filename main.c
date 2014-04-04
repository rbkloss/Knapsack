/*
 * main.c
 *
 *  Created on: Nov 22, 2013
 *      Author: ricardo
 */

#include <stdio.h>
#include <stdlib.h>

#include "Knapsack.h"
#include "List.h"

int main(int argc, char** argv) {

	KnapsackElement* els[4];
	int it = 0;
	for (it = 0; it < 4; it++) {
		els[it] = NULL;
	}

	instantiateKnapsackElement(&(els[0]), 1, 8, 6);
	instantiateKnapsackElement(&(els[1]), 2, 7, 3);
	instantiateKnapsackElement(&(els[2]), 3, 5, 4);
	instantiateKnapsackElement(&(els[3]), 4, 2, 2);

	Knapsack* knapsack_sol[10];
	for (it = 0; it < 10; it++) {
		knapsack_sol[it] = NULL;
	}
	solveKnapsackProblem(els, 4, knapsack_sol, 10);

	for (it = 0; it < 10; it++) {
		printKnapsack(knapsack_sol[it]);
	}

	for (it = 0; it < 10; it++) {
		freeKnapsack(&(knapsack_sol[it]));
	}
	for (it = 0; it < 4; it++) {
		freeknapsackElement(&(els[it]));
	}

	return 0;
}
