#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

struct node {
    int data;
    struct node *next;
};

struct list {
    Node *head;
};

Node *createNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return NULL;

    new->data = data;
    new->next = NULL;

    return new;
}

List *createList() {
    List *list = (List *)malloc(sizeof(List));
    if (!list) return NULL;

    list->head = NULL;
    return list;
}

int listLength(List *list) {
    int length = 0;

    Node *current = list->head;
    if (list->head == NULL) return 0;

    while(current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

void addAtStart(List *list, int data) {
    Node *new = createNode(data);

    if (list->head == NULL) {
        list->head = new;
    } else {
        new->next = list->head;
        list->head = new;
    }
}

void addAtEnd(List *list, int data) {
    Node *new = createNode(data);
    Node *current = list->head;

    if (list->head == NULL) {
        list->head = new;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void removeAtStart(List *list) {
    if (list->head == NULL) {
        printf("Empty list\n\n");
    } else {
        Node *current = list->head;
        list->head = current->next;
        free(current);
        current = NULL;
    }
}

void removeAtEnd(List *list) {
    if (list->head == NULL) {
        printf("Empty list\n\n");
    } else if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        // Remove last element of the list using TWO POINTERS

        // Node *current = list->head;
        // Node *prev = current;

        // while (current->next != NULL) {
        //     prev = current;
        //     current = current->next;
        // }

        // prev->next = NULL;
        // free(current);
        // current = NULL;

        // Remove last element of the list using ONE POINTER
        Node *current = list->head;

        while (current->next->next != NULL) {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }
}

void insertNode(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position\n\n");
        return;
    }

    // Insert node at the beginning of the list
    if (pos == 1) {
        addAtStart(list, data);
        return;
    }

    // Insert node at the end of the list
    if (pos == len + 1) {
        addAtEnd(list, data);
        return;
    }

    Node *current = list->head;
    Node *new = createNode(data);

    pos--;
    while(pos != 1) {
        current = current->next;
        pos--;
    }

    new->next = current->next;
    current->next = new;
}

void removeNode(List *list, int data) {
    Node *current = list->head;
    Node *prev = current;

    while (current != NULL) {
        if (current->data == data) {
            if (current == list->head) {
                list->head = current->next;
            } else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return;
        }

        prev = current;
        current = current->next;
    }
}

void reverse(List *list) {
    Node *prev = NULL;
    Node *next = NULL;

    while (list->head != NULL) {
        next = list->head->next;
        list->head->next = prev;
        prev = list->head;
        list->head = next;
    }

    list->head = prev;
}

void printList(List *list) {
    Node *current = list->head;
    if (list->head == NULL) {
        printf("Empty list\n\n");
        return;
    }

    while(current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n\n");
}

void freeList(List *list) {
    Node *current = list->head;
    Node *next = current;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
