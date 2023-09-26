#include "sort.h"
#include <stdio.h>

/**
 * hoare_partition - Implement Hoare's partition scheme
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;
    int temp = array[i];

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        if (i != j)
        {
           
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
}

/**
 * quicksort_hoare - Implement the quicksort algorithm using Hoare's scheme
 * @array: The array to be sorted
 * @low: The starting index of the array or partition to be sorted
 * @high: The ending index of the array or partition to be sorted
 * @size: The size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare's partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
