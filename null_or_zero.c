#include "shell.h"

/**
 * set_zeros - set a zero value
 * @arr: pointer to the array
 * @size: size of the array
 */

void set_zeros(unsigned int *arr, size_t size)
{
        size_t x;

        for (x = 0; x < size; x++)
                arr[x] = 0;
}
