#ifndef DLL
#define DLL

typedef struct node Node;

typedef struct list List;

Node *createNode(int data);

List *createList();

int listLength(List *list);

void addAtStart(List *list, int data);

void addAtEnd(List *list, int data);

void removeAtStart(List *list);

void removeAtEnd(List *list);

void insertNodeBefore(List *list, int data, int pos);

void insertNodeAfter(List *list, int data, int pos);

void removeNode(List *list, int data);

void printList(List *list);

void reverse(List *list);

void freeList(List *list);

#endif
