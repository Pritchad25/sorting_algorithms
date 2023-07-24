#include "sort.h"

/**
 * get_max - this function gets the maximum value in an array
 * of integers.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Return: the maximum integer in the array (Success)
 */
int get_max(int *array, int size)
{
	int a, max;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * counting_sort - this function sorts an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function prints the counting array after
 * setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int max, b, *count, *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (b = 0; b < (max + 1); b++)
		count[b] = 0;
	for (b = 0; b < (int)size; b++)
		count[array[b]] += 1;
	for (b = 0; b < (max + 1); b++)
		count[b] += count[b - 1];
	print_array(count, max + 1);

	for (b = 0; b < (int)size; b++)
	{
		sorted[count[array[b]] - 1] = array[b];
		count[array[b]] -= 1;
	}

	for (b = 0; b < (int)size; b++)
		array[b] = sorted[b];

	free(sorted);
	free(count);
}
