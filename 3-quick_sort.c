#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array.
 * @array: The array containing the elements to be swapped.
 * @a: Index of the first element.
 * @b: Index of the second element.
 */
void swap(int *array, int a, int b)
{
    if (array[a] != array[b])
    {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        print_array(array, a);
    }
}

/**
 * lomuto_partition - Partition an array using Lomuto scheme.
 * @array: The array to be partitioned.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The size of the array.
 * Return: The index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    j = low; 
    while (j <= high - 1)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	    print_array(array, j);
        }
	j++;
    }
    temp = array[i +1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, high);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, pi - 1);
        quick_sort_recursive(array, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}
