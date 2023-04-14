#include <stdio.h>
#include <stdlib.h>

// Clear Allocation
// Used to dinamically allocate multiple blocks of memory
// Memory allocated by calloc is initialized to zero
//
int main()
{
    int *ptr_malloc = (int* )malloc(10 * sizeof(int));
    int *ptr_calloc = (int* )calloc(10, sizeof(int));
    
    return 0;
}
