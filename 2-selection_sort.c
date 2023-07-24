#include "sort.h"

/**
 * swap_ints - this function swaps two integers in an array.
 * @a: the first integer to swap.
 * @b: the second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - this function sorts an array of integers
 * in ascending order using the selection sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: the function prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t j, k;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
		{
			min = (array[k] < *min) ? (array + k) : min;
		}

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
