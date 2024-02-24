#include "sort.h"

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
 * selection_sort - Sort an array of integers in ascending order
 * to using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min = array + m;
		for (n = m + 1; n < size; n++)
			min = (array[n] < *min) ? (array + n) : min;

		if ((array + m) != min)
		{
			swap_intz(array + m, min);
			print_array(array, size);
		}
	}
}
