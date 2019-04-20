#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

int main(int argc, const char * argv[]){
	printf("Running\n");

	struct SortedList *x;
	x = createSortedList();
	insertSorted(x,3);
	insertSorted(x,4);
	insertSorted(x,2);
	insertSorted(x,1);
	insertSorted(x,9);
	insertSorted(x,5);

	printList(x);

	int i = findSorted(x,3);
	int j = findSorted(x,6);

	printf("3: %d\n", i);
	printf("6: %d\n", j);

	removeSorted(x, 3);
	removeSorted(x,5);
	insertSorted(x,6);

	printList(x);

	i = findSorted(x,3);
	j = findSorted(x,6);

	printf("3: %d\n", i);
	printf("6: %d\n", j);

	destroySortedList(x);

	printf("Complete\n");
}