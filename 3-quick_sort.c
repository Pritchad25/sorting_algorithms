#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - this function orders a subset of an array
 * of integers according to the lomuto partition scheme
 * (last element as pivot).
 * @array: the array of integers.
 * @size: the size of the array.
 * @left: the starting index of the subset to order.
 * @right: the ending index of the subset to order.
 *
 * Return: the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int up, down;
	int *driver;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - this function implements the quicksort algorithm
 * through recursion.
 * @array: an array of integers to sort.
 * @size: the size of the array.
 * @left: the starting index of the array partition to order.
 * @right: the ending index of the array partition to order.
 *
 * Description: this function uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - this function sorts an array of integers in
 * ascending order using the quicksort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function uses the Lomuto partition scheme.
 * The function prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
