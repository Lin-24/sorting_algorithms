#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing the elements.
 * @size: Size of the array.
 * @a: Index of the first element to swap.
 * @b: Index of the second element to swap.
 */
void swap(int *array, size_t size, int a, int b)
{
	int temp;

	if (a != b)
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * sift_down - Performs sift-down operation on a binary heap.
 * @array: The array representing the binary heap.
 * @size: Size of the array.
 * @start: Index to start the sift-down operation from.
 * @end: The last index in the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap_idx;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(array, size, root, swap_idx);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, (size_t)i, size - 1);
	
	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		sift_down(array, size, 0, i - 1);
	}
}
