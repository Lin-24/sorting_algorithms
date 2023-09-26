#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	int min = 0;
	size_t i;
	int *counting_arr, *output_arr;
	size_t j = 0;
	size_t range = (size_t)(max - min + 1);

	if (array == NULL || size < 2)
		return;

	max = array[0];
	min = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	counting_arr = malloc(sizeof(int) * range);
	if (counting_arr == NULL)
		return;
	for (i = 0; i < (size_t)range; i++)
		counting_arr[i] = 0;

	for (i = 0; i < size; i++)
		counting_arr[array[i] - min]++;

	print_array(counting_arr, range);

	output_arr = malloc(sizeof(int) * size);
	if (output_arr == NULL)
	{
		free(counting_arr);
		return;
	}

	for (i = 0; i < range; i++)
	{
		while (counting_arr[i] > 0)
		{
			output_arr[j] = i + min;
			counting_arr[i]--;
			j++;
		}
	}

	for (i = 0; i < size; i++)
		array[i] = output_arr[i];

	print_array(array, size);

	free(counting_arr);
	free(output_arr);
}
