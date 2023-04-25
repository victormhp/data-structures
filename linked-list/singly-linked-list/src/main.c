#include <stdio.h>
#include "sll.h"

void printMenu() {
    printf("---- Single Linked List ----\n\n");
    printf("1. Add node at start\n");
    printf("2. Add node at end\n");
    printf("3. Remove node at start\n");
    printf("4. Remove node at end\n");
    printf("5. Insert node at n position\n");
    printf("6. Remove Node\n");
    printf("7. Reverse list\n");
    printf("8. Print Linked List\n");
    printf("9. Exit\n\n");
    printf("Choose an option: ");
}

int main() {
    List *list = createList();
    int option = -1;
    int arg1 = 0;
    int arg2 = 0;

    do {
        printMenu();
        int num = scanf("%d", &option);

        if (num != 1 || option < 1 || option > 9) {
            printf("Invalid option. Please try again.\n\n");
            while (getchar() != '\n'); // Flush input buffer
            continue;
        }

        switch(option) {
            case 1:
                printf("Data to insert: ");
                scanf("%d", &arg1);
                addAtStart(list, arg1);
                break;
            case 2:
                printf("Data to insert: ");
                scanf("%d", &arg1);
                addAtEnd(list, arg1);
                break;
            case 3:
                removeAtStart(list);
                break;
            case 4:
                removeAtEnd(list);
                break;
            case 5:
                printf("Data to insert: ");
                scanf("%d", &arg1);
                printf("Position: ");
                scanf("%d", &arg2);
                insertNode(list, arg1, arg2);
                break;
            case 6:
                printf("Data to remove: ");
                scanf("%d", &arg1);
                removeNode(list, arg1);
                break;
            case 7:
                reverse(list);
                break;
            case 8:
                printList(list);
                break;
            case 9:
                break;
        }
    } while (option != 9);

    freeList(list);
    return 0;
}
