/*
 * List.h
 *
 *  Created on: Nov 22, 2013
 *      Author: ricardo
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	void* element;
	struct ListNode* next;
	int aux;

} ListNode;

typedef struct ListHead {
	ListNode* head;
	int len;

} ListHead;

void initListHead(ListHead** head);
void initListNode(ListNode** node);

void freeNode(ListNode** node);
void freeList(ListHead** head);

void addNode(ListHead* head, ListNode* node);

ListNode* copyNode(ListNode* node);
ListHead* copyList(ListHead* head);

void removeNode(ListHead* head, ListNode* node);

void printElement(void *element);
void printNode(ListNode* node);
void printList(ListHead* head);

#endif /* LIST_H_ */
