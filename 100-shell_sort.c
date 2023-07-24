#include "sort.h"

/**
 * swap_ints - this function swap two integers in an array.
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
 * shell_sort - this function sorts an array of integers
 * in ascending order using the shell sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
	{
		gap = gap * 3 + 1;
	}

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_ints(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
