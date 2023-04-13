#include <stdio.h>

// Uninitialized pointers, points to some arbitrary memory location.

int main()
{
    int *ptr;
    *ptr = 10;

    return 0;
}
