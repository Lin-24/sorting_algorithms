#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of the array.
 * @array: The array to be sorted.
 * @temp: Temporary array for merging.
 * @left: Pointer to the left subarray.
 * @mid: Middle index.
 * @right: Pointer to the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = left, j = mid + 1, k = 0; i <= mid && j <= right; k++)
	{
		if (array[i] <= array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (k = 0, i = left; i <= right; k++, i++)
		array[i] = temp[k];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_helper - Recursive helper function for Merge Sort.
 * @array: The array to be sorted.
 * @temp: Temporary array for merging.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */
void merge_sort_helper(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;

		merge_sort_helper(array, temp, left, mid);
		merge_sort_helper(array, temp, mid + 1, right);
		merge(array, temp, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
