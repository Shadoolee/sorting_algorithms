#include "sort.h"

void swap_intz(int *c, int *d);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - It swap da two integerz in an array.
 * @a: Da first integer to swap.
 * @b: Da second integer to swap.
 */
void swap_intz(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * lomuto_partition - Da order a subset of an array of integerz according to
 * da lomuto partition scheme (last element as pivot).
 * @array: Da array of integers.
 * @size: Da size of da array.
 * @left: Da starting index of the subset to order.
 * @right: Da ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_intz(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_intz(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement da quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: Da size of the array.
 * @left: Da starting index of da array partition to order.
 * @right: Da ending index of da array partition to order.
 *
 * Description: It usez da Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integerz in ascending
 *              order uzing the quicksort algorithm.
 * @array: An array of integers.
 * @size: Da size of da array.
 *
 * Description: Usez da Lomuto partition scheme. Printz
 *              the array after each swap of two elementz.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
