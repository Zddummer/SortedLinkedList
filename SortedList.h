// implements a sorted (DESCENDING ORDER) linked list of ints
// The list can contain duplicates

struct SortedList {
	struct SortedNode *head;
};

struct SortedNode {
	int data;
	struct SortedNode *next;
};

//return a new empty list
struct SortedList * createSortedList();

//PRE: aList has been created and is sorted in descending order
//insert x into aList so it remains sorted
void insertSorted(struct SortedList *aList, int x);

//PRE: aList has been created and is sorted in descending order
//remove all occurrences of x from aList (the list remains sorted)
void removeSorted(struct SortedList *aList, int x);

//PRE: aList has been created and is sorted in descending order
//return 1 if x is in aList otherwise return 0
int findSorted(struct SortedList *aList, int x);

//PRE: aList has been created
//free the space created for aList
void destroySortedList(struct SortedList *aList);

//PRE: aList has been created
//print the contents of the list to standard out
//the elements in the list should be separated by commas
void printList(struct SortedList *aList);
