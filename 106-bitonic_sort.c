#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function to perform bitonic merge */
void bitonic_merge(int *array, size_t size, int up);

/* Function to perform bitonic sort */
void bitonic_sort_recursive(int *array, size_t size, int up);

/* Main bitonic sort function */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, size, 1); // 1 represents 'up' direction (ascending)
}

/* Function to perform bitonic merge */
void bitonic_merge(int *array, size_t size, int up)
{
    if (size > 1)
    {
        size_t half = size / 2;
        
        // Split the array into two halves
        bitonic_merge(array, half, 1);     // Bitonic merge on the first half (upwards)
        bitonic_merge(array + half, half, 0); // Bitonic merge on the second half (downwards)
        
        // Merge the two halves
        for (size_t i = 0; i < half; i++)
        {
            if ((array[i] > array[i + half]) == up)
            {
                // Swap elements to maintain the bitonic property
                int temp = array[i];
                array[i] = array[i + half];
                array[i + half] = temp;
            }
        }
    }
}

/* Function to perform bitonic sort recursively */
void bitonic_sort_recursive(int *array, size_t size, int up)
{
    if (size > 1)
    {
        size_t half = size / 2;

        // Recursively sort the first half
        bitonic_sort_recursive(array, half, 1);     // Bitonic sort in the first half (upwards)
        bitonic_sort_recursive(array + half, half, 0); // Bitonic sort in the second half (downwards)

        // Merge the sorted halves
        bitonic_merge(array, size, up);
    }
}
