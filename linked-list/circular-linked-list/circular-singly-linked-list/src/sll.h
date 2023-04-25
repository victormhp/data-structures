#ifndef SLL
#define SLL

typedef struct node Node;

typedef struct list List;

Node *createNode(int data);

List *createList();

int listLength(List *list);

int searchElement(List *list, int element);

void addAtStart(List *list, int data);

void addAtEnd(List *list, int data);

void removeAtStart(List *list);

void removeAtEnd(List *list);

void insertNode(List *list, int data, int pos);

void removeNode(List *list, int pos);

void printList(List *list);

void reverse(List *list);

void freeList(List *list);

#endif
