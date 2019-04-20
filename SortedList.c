#include "SortedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct SortedList * createSortedList() {
	struct SortedList * list;
	list = (struct SortedList *) malloc(sizeof(struct SortedList));
	list->head = NULL;
	return list;
}

void insertSorted(struct SortedList *aList, int x){
	struct SortedNode *node;
	node = (struct SortedNode *) malloc(sizeof(struct SortedNode));
	node->data = x;

	if(aList->head == NULL){
		aList->head = node;
		node->next = NULL;
	} else {
		struct SortedNode *temp = aList->head;
		struct SortedNode *prev = NULL;
		while(temp != NULL){
			int i = temp->data;
			if(x < i){
				prev = temp;
				temp = temp->next;
			}
			else {
				break;
			}
		}
		if(prev != NULL){
			prev->next = node;
			node->next = temp;
		}
		else {
			node->next = temp;
			aList->head = node;
		}
	}
}

void removeSorted(struct SortedList *aList, int x){
	if(aList->head == NULL){
		return;
	}

	struct SortedNode *temp = aList->head;
	struct SortedNode *prev = NULL;

	while(temp != NULL){
		if(temp->data == x){
			prev->next = temp->next;
		}
		prev = temp;
		temp = temp->next;
	}
}

int findSorted(struct SortedList *aList, int x){
	if(aList->head == NULL){
		return 0;
	}

	struct SortedNode *temp = aList->head;
	struct SortedNode *prev = NULL;

	while(temp != NULL){
		if(temp->data == x){
			return 1;
		}
		prev = temp;
		temp = temp->next;
	}
	return 0;
}

void destroySortedList(struct SortedList *aList){
	struct SortedNode * temp;
	struct SortedNode * temp1;
	temp = aList->head;
	while(temp != NULL){
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
	free(aList);
}

void printList(struct SortedList *aList){
	printf("printing list\n");
	struct SortedNode * temp;
	temp = aList->head;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}