#include <stdio.h>

// Void pointer is a pointer which has no assocaited data type with it.
// It can point to any data of any data type and be typecasted to any type.
// We need to typecast the pointer before dereferencing it.

// Malloc a calloc functions returns a void pointer. 
// They can allocate memory for any type of data.

int main() 
{
    int n = 10;
    void *ptr = &n;

    printf("%d\n", *(int*)ptr);
    return 0;
}
