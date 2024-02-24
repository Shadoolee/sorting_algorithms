#include "sort.h"

/**
 * swap_intz - It swap two integerz in an array.
 * @c: Da first integer to swap.
 * @d: Da second integer to swap.
 */
void swap_intz(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * shell_sort - It Sort an array of integerz in ascending
 *              order using da shell sort algorithm.
 * @array: An array of integerz.
 * @size: Da Zize of the array.
 *
 * Description: It Usez da Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				swap_intz(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
