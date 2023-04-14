#include <stdio.h>
#include <stdlib.h>

// Used to change the size of the memory block without losing the old data  

int main()
{
    int i;
    int *ptr = (int*)malloc(2 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memoy not available");
        exit(1);
    }

    printf("Enter the two numbers: \n");
    for (i = 0; i < 2; i++) 
        scanf("%d", ptr + i);
    

    // Memory allocation for two more integers.
    ptr = (int* )realloc(ptr, 4 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not available");
        exit(1);
    }

    printf("Enter two more integers: \n");
    for (i = 2; i < 4; i++) 
        scanf("%d", ptr + i);
    
    
    for (i = 0; i < 4; i++) 
        printf("%d ", *(ptr + i));

    printf("\n");

    return 0;
}
