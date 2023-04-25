#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

struct node {
    int data;
    struct node *next;
};

struct list {
    Node *tail;
};

Node *createNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return NULL;

    new->data = data;
    new->next = new;

    return new;
}

List *createList() {
    List *list = (List *)malloc(sizeof(List));
    if (!list) return NULL;

    list->tail = NULL;
    return list;
}

int listLength(List *list) {
    if (list->tail == NULL) return 0;

    int length = 0;
    Node *current = list->tail->next;

    while (current != list->tail) {
        current = current->next;
        length++;
    }
    length++;

    return length;
}

int searchElement(List *list, int element) {
    Node *current;
    int index = 0;

    if (list->tail == NULL) return -2;

    current = list->tail->next;
    do {
        if (current->data == element)
            return index;
        current = current->next;
        index++;
    } while (current != list->tail->next);

    return -1;
}

void addAtStart(List *list, int data) {
    Node *new = NULL;

    if (list->tail == NULL) {
        new = createNode(data);
        list->tail = new;
    } else {
        new = createNode(data);
        new->next = list->tail->next;
        list->tail->next = new;
    }
}

void addAtEnd(List *list, int data) {
    Node *new = NULL;

    if (list->tail == NULL) {
        new = createNode(data);
        list->tail = new;
    } else {
        new = createNode(data);
        new->next = list->tail->next;
        list->tail->next = new;
        list->tail = list->tail->next;
    }
}

void removeAtStart(List *list) {
    if (list->tail == NULL) {
        printf("Empty list\n\n");
    } else if(list->tail->next == list->tail) {
        free(list->tail);
        list->tail = NULL;
    } else {
        Node *head = list->tail->next;
        list->tail->next = head->next;
        free(head);
        head = NULL;
    }
}

void removeAtEnd(List *list) {
    if (list->tail == NULL) {
        printf("Empty list\n\n");
    } else if (list->tail->next == list->tail) {
        free(list->tail);
        list->tail = NULL;
    } else {
        Node *current = list->tail->next;

        while (current->next != list->tail) {
            current = current->next;
        }

        current->next = list->tail->next;
        free(list->tail);
        list->tail = current;
    }
}

void insertNode(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position\n\n");
        return;
    }

    if (pos == 1) {
        addAtStart(list, data);
        return;
    }

    Node *current = list->tail->next;
    Node *new = createNode(data);

    while(pos > 2) {
        current = current->next;
        pos--;
    }

    new->next = current->next;
    current->next = new;

    if (current == list->tail)
        list->tail = list->tail->next;
}

void removeNode(List *list, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n\n");
        return;
    }

    if (list->tail == NULL) return;

    if (pos == 1) {
        removeAtStart(list);
        return;
    }

    Node *prev = list->tail->next;
    while (pos > 2) {
        prev = prev->next;
        pos--;
    }

    Node *node_to_delete  = prev->next;
    prev->next = node_to_delete->next;

    // Handling the case of deleting the last node
    if (node_to_delete == list->tail)
        list->tail = prev;

    free(node_to_delete);
    node_to_delete = NULL;
}

void reverse(List *list) {
    Node *prev = NULL;
    Node *next = NULL;

    while (list->tail != NULL) {
        next = list->tail->next;
        list->tail->next = prev;
        prev = list->tail;
        list->tail = next;
    }

    list->tail = prev;
}

void printList(List *list) {
    if (list->tail == NULL) {
        printf("Empty list\n\n");
        return;
    }

    Node *current = list->tail->next;

    do {
        printf("%d->", current->data);
        current = current->next;
    } while (current != list->tail->next);

    printf("\n\n");
}

void freeList(List *list) {
    if (list->tail == NULL) return;

    Node *current = list->tail->next;
    Node *next = NULL;

    while (current != list->tail) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list->tail);
    list->tail = NULL;
}
