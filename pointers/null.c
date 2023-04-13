#include <stdio.h>
#include <stdlib.h>

// A NULL pointer is a pointer that does not point to any memory location.
// It represents an invalid memory location.

// Uses
// Initialize a pointer when that pointer isn't assigned any valid memory address yet.
// Useful for handling errors when using malloc function.

int main()
{
    int *null_ptr_value = NULL;
    int *ptr;
    ptr = (int*)malloc(2 * sizeof(int));

    if (ptr == NULL)
        printf("Memory could not be allocated\n");
    else
        printf("Memory allocated succesfully\n");

    printf("The value of NULL is %d\n", null_ptr_value);
    return 0;
}
