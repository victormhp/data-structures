#ifndef DLL
#define DLL

typedef struct node Node;

typedef struct list List;

Node *createNode(int data);

List *createList();

void addAtStart(List *list, int data);

void addAtEnd(List *list, int data);

void removeAtStart(List *list);

void removeAtEnd(List *list);

void insertNodeBefore(List *list, int data, int pos);

void insertNodeAfter(List *list, int data, int pos);

void removeNode(List *list, int data);

void printList(List *list);

void printLength(List *list);

void reverse(List *list);

void freeList(List *list);

#endif
