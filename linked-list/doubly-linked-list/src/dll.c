#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct list {
    Node *head;
};

Node *createNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return NULL;

    new->prev = NULL;
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
        list->head->prev = new;
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
        new->prev = current;
    }
}

void removeAtStart(List *list) {
    if (list->head == NULL) {
        printf("Empty list\n\n");
    } else {
        Node *current = list->head;
        list->head = current->next;
        list->head->prev = NULL;
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
        Node *current = list->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->prev->next = NULL;
        free(current);
        current = NULL;
   }
}

void insertNodeBefore(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n\n");
        return;
    }

    Node *current = list->head;
    Node *curr_next = NULL;
    Node *new = createNode(data);

    while(pos > 2) {
        current = current->next;
        pos--;
    }

    if (pos == 1) {
        addAtStart(list, data);
    } else {
        curr_next = current->next;
        current->next = new;
        curr_next->prev = new;
        new->next = curr_next;
        new ->prev = current;
    }
}

void insertNodeAfter(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n\n");
        return;
    }

    Node *current = list->head;
    Node *curr_next = NULL;
    Node *new = createNode(data);

    while(pos != 1) {
        current = current->next;
        pos--;
    }

    if (current->next == NULL) {
        current->next = new;
        new->prev = current;
    } else {
        curr_next = current->next;
        current->next = new;
        curr_next->prev = new;
        new->next = curr_next;
        new ->prev = current;
    }
}

void removeNode(List *list, int pos) {
    Node *current = list->head;
    Node *curr_prev = NULL;

    if (pos == 1 ) removeAtStart(list);

    while (pos > 1) {
        current = current->next;
        pos--;
    }

    if (current->next == NULL) {
        removeAtEnd(list);
    } else {
        curr_prev = current->prev;
        curr_prev->next = current->next;
        current->next->prev = curr_prev;
        free(current);
        current = NULL;
    }
}

void reverse(List *list) {
    Node *current = list->head;
    Node *curr_next = current->next;

    current->next = NULL;
    current->prev = curr_next;

    while (curr_next != NULL) {
        curr_next->prev = curr_next->next;
        curr_next->next = current;
        current = curr_next;
        curr_next = curr_next->prev;
    }

    list->head = current;
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
