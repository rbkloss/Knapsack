/*
 * List.c
 *
 *  Created on: Nov 22, 2013
 *      Author: ricardo
 */
#include "List.h"

void initListHead(ListHead** head) {
	ListHead* list = NULL;

	(*head) = malloc(sizeof(ListHead));
	list = (*head);
	list->head = NULL;
	list->len = 0;
}

void initListNode(ListNode** node) {

	(*node) = malloc(sizeof(ListNode));
	ListNode* n = (*node);
	n->element = NULL;
	n->next = NULL;
}

void addNode(ListHead* head, ListNode* node) {
	ListNode* n = head->head;
	if (n == NULL) {
		head->head = node;
		return;
	}

	while (n->next != NULL)
		;
	n->next = node;
	head->len++;
}

void freeNode(ListNode** node) {
	if ((*node) == NULL) {
		return;
	}
	freeNode(&((*node)->next));
	(*node)->next = NULL;
	free((*node));
	(*node) = NULL;
}

ListNode* copyNode(ListNode* node) {
	ListNode* new_node = NULL;
	initListNode(&new_node);
	new_node->element = node->element;
	new_node->aux = node->aux;
	new_node->next = NULL;

	return new_node;
}

void removeNode(ListHead* head, ListNode* node) {
	ListNode* n = head->head;

	while (n->next != node)
		;
	n->next = node->next;
	node->next = NULL;
	freeNode(&node);
}

void freeList(ListHead** head) {
	freeNode(&((*head)->head));
}

ListHead* copyList(ListHead* head) {
	if (head == NULL) {
		return NULL;
	}
	ListHead* new_list = NULL;
	initListHead(&new_list);
	ListNode* n = NULL;
	n = head->head;

	while (n->next != NULL) {
		ListNode* c_node = NULL;
		c_node = copyNode(n);
		addNode(new_list, c_node);
	}
	if (n != NULL) {
		ListNode* c_node = NULL;
		c_node = copyNode(n);
		addNode(new_list, c_node);
	}

	return new_list;
}

void printNode(ListNode* node) {
	printf("\tNODE: aux[%d]\n\t", node->aux);
	printElement(node->element);
	printf("\n");
}

void printList(ListHead* head) {
	if (head == NULL) {
		return;
	}
	ListNode* n = head->head;
	if (n == NULL) {
		return;
	}

	printf("LIST:\n");
	int it = 0;
	while (n->next != NULL || it < head->len) {
		printNode(n);
		it++;
		n = n->next;
	}
	printNode(n);
	return;
}
