#include <stdio.h>

// A pointer which points to some non-existing memory location.

int *function ()
{
    int num = 10;
    return &num;
}

int main()
{
    int *ptr = NULL;
    ptr = function();

    printf("%d\n", *ptr); // Segmentation fault
    return 0;
}
