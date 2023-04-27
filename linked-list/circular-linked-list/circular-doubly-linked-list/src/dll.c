#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct list {
    Node *tail;
};

Node *createNode(int data) {
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) return NULL;

    new->prev = new;
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
    int length = 0;

    if (list->tail == NULL) return 0;

    Node *current = list->tail->next;
    do {
        current = current->next;
        length++;
    } while (current != list->tail->next);

    return length;
}

void addAtStart(List *list, int data) {
    Node *new = createNode(data);

    if (list->tail == NULL) {
        list->tail = new;
    } else {
        Node *head = list->tail->next;

        new->prev = list->tail;
        new->next = head;
        head->prev = new;
        list->tail->next = new;
    }
}

void addAtEnd(List *list, int data) {
    Node *new = createNode(data);

    if (list->tail == NULL) {
        list->tail = new;
    } else {
        Node *head = list->tail->next;

        new->prev = list->tail;
        new->next = head;
        list->tail->next = new;
        head->prev = new;
        list->tail = new;
    }
}

void removeAtStart(List *list) {
    if (list->tail == NULL) {
        printf("Empty list\n");
        return;
    }

    Node *head = list->tail->next;

    if (list->tail == head) {
        free(list->tail);
        list->tail = NULL;
        return;
    }

    list->tail->next = head->next;
    head->next->prev = list->tail;
    free(head);
}

void removeAtEnd(List *list) {
    if (list->tail == NULL) {
        printf("Empty list\n");
        return;
    }

    Node *head = list->tail->next;
    if (list->tail == head) {
        free(list->tail);
        list->tail = NULL;
        return;
    }

    Node *new_tail = list->tail->prev;

    new_tail->next = head;
    head->prev = new_tail;
    free(list->tail);
    list->tail = new_tail;
}

void insertNodeBefore(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        addAtStart(list, data);
    }

    Node *current = list->tail->next;

    while(pos > 2) {
        current = current->next;
        pos--;
    }

    Node *curr_next = current->next;
    Node *new = createNode(data);

    current->next = new;
    curr_next->prev = new;
    new->next = curr_next;
    new->prev = current;
}

void insertNodeAfter(List *list, int data, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        return;
    }

    Node *current = list->tail->next;
    Node *new = createNode(data);

    while(pos != 1) {
        current = current->next;
        pos--;
    }

    if (current->next == list->tail->next) {
        addAtEnd(list, data);
    } else {
        Node *curr_next = current->next;

        current->next = new;
        curr_next->prev = new;
        new->next = curr_next;
        new ->prev = current;
    }
}

void removeNode(List *list, int pos) {
    // Check if position valid
    int len = listLength(list);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1 ) removeAtStart(list);

    Node *current = list->tail->next;
    while (pos > 1) {
        current = current->next;
        pos--;
    }

    Node *curr_prev = current->prev;

    curr_prev->next = current->next;
    current->next->prev = curr_prev;
    free(current);
    current = NULL;
}

void reverse(List *list) {
    if (list->tail == NULL) return;

    Node *temp = NULL;
    Node *current = list->tail;

    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != list->tail);

    list->tail = list->tail->prev;
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
}

void freeList(List *list) {
    if (list->tail == NULL) return;

    Node *current = list->tail;
    Node *next = NULL;

    while (current != list->tail) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list->tail);
    list->tail = NULL;
}
