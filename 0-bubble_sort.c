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
 * bubble_sort - this function sorts an array of integers in
 * ascending order.
 * @array: the array of integers to sort.
 * @size: the size of the array.
 *
 * Description: this function prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	bool bubbly = false;
	size_t i, len = size;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
