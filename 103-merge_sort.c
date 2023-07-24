#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarr(int *subarr, int *buff, size_t front,
		size_t mid, size_t back);

/**
 * merge_subarr - this function sorts a subarray of integers.
 * @subarr: the subarray of an array of integers to sort.
 * @buff: a buffer to store the sorted subarray.
 * @front: the front index of the array.
 * @mid: the middle index of the array.
 * @back: the back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front,
		size_t mid, size_t back)
{
	size_t a, b, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; k++)
		buff[k] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[k++] = subarr[a];
	for (; b < back; b++)
		buff[k++] = subarr[b];
	for (a = front, k = 0; a < back; a++)
		subarr[a] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - this function implements the merge
 * sort algorithm through recursion.
 * @subarr: the subarray of an array of integers to sort.
 * @buff: the buffer to store the sorted result.
 * @front: the front index of the subarray.
 * @back: the back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - this function sorts an array of integers
 * in ascending order using the merge sort algorithm.
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: this function implements the top-down merge
 * sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
