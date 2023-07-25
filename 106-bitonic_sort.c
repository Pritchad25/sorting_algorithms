#include "sort.h"

void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq, char flow);
void swap_ints(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * swap_ints - this function swaps 2 integers in an array.
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
 * bitonic_merge - this function sorts a bitonic sequence inside
 * an array of integers.
 * @array: the array of integers.
 * @size: the size of the array.
 * @start: the starting index of the sequence in array to sort.
 * @seq: the size of the sequence to sort.
 * @flow: the direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq, char flow)
{
	size_t d, jump = seq / 2;

	if (seq > 1)
	{
		for (d = start; d < start + jump; d++)
		{
			if ((flow == UP && array[d] > array[d + jump]) ||
			    (flow == DOWN && array[d] < array[d + jump]))
				swap_ints(array + d, array + d + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - this function converts an array of integers
 * into a bitonic sequence.
 * @array: the array of integers.
 * @size: the size of the array.
 * @start: the starting index of a block of the building bitonic sequence.
 * @seq: the size of a block of the building bitonic sequence.
 * @flow: the direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	char *str = (flow == UP) ? "UP" : "DOWN";
	size_t cut = seq / 2;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - this function sorts an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function prints the array after each swap.
 * This only works for size = 2^k where k >= 0, that is, size equal
 * to powers of 2.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_seq(array, size, 0, size, UP);
}
