#include "sort.h"

void swap_intz(int *c, int *d);
int hoare_partitionz(int *array, size_t size, int left, int right);
void hoare_sortz(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_intz - It Swaps two integerz in an array.
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
 * hoare_partitionz - It Order a subset of an array of integerz
 * according to the hoare partition scheme.
 * @array: Da array of integerz.
 * @size: Da size of da array.
 * @left: Da starting index of da subset to order.
 * @right: Da ending index of da subset to order.
 *
 * Return: Da final partition index.
 *
 * Description: Uses da last element of da partition as da pivot.
 * Printz the array after each swapz of two elementz.
 */
int hoare_partitionz(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_intz(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sortz - It Implement da quicksort algorithm through recursion.
 * @array: An array of integerz to sort.
 * @size: Da size of da array.
 * @left: Da starting index of da array partition to order.
 * @right: Da ending index of da array partition to order.
 *
 * Description: It Uses da Hoare partition scheme.
 */
void hoare_sortz(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partitionz(array, size, left, right);
		hoare_sortz(array, size, left, part - 1);
		hoare_sortz(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - It Sortz an array of integerz in ascending
 * order using da quicksort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 *
 * Description: Uses da Hoare partition scheme. Printz
 * da array after each swap of two elementz.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sortz(array, size, 0, size - 1);
}
