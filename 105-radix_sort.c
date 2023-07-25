#include "sort.h"

void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
int get_max(int *array, int size);

/**
 * get_max - this function gets the maximum value in an array of integers.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Return: the maximum integer in the array (Success)
 */
int get_max(int *array, int size)
{
	int b, max;

	for (max = array[0], b = 1; b < size; b++)
	{
		if (array[b] > max)
		{
			max = array[b];
		}
	}

	return (max);
}

/**
 * radix_counting_sort - this function sorts the significant digits
 * of an array of integers in ascending order using the
 * counting sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 * @sig: the significant digit to sort on.
 * @buff: a buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	size_t c;
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (c = 0; c < size; c++)
	{
		count[(array[c] / sig) % 10] += 1;
	}

	for (c = 0; c < 10; c++)
		count[c] += count[c - 1];

	for (c = size - 1; (int)c >= 0; c--)
	{
		buff[count[(array[c] / sig) % 10] - 1] = array[c];
		count[(array[c] / sig) % 10] -= 1;
	}

	for (c = 0; c < size; c++)
	{
		array[c] = buff[c];
	}
}

/**
 * radix_sort - this function sorts an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function implements the LSD radix sort algorithm.
 * The function prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int *buff, max, sig;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	{
		return;
	}
	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
