#include "sort.h"

void swap_intz(int *c, int *d);
void max_heapifyz(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_intz - Swap two integers in an array.
 * @c: Da first integerz to swap.
 * @d: Da second integerz to swap.
 */
void swap_intz(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * max_heapifyz - It Turn a binary tree into a complete binary heap.
 * @array: An array of integerz representing a binary tree.
 * @size: Da size of da array/tree.
 * @base: Da index of da base row of da tree.
 * @root: Da root node of da binary tree.
 */
void max_heapifyz(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_intz(array + root, array + large);
		print_array(array, size);
		max_heapifyz(array, size, base, large);
	}
}

/**
 * heap_sort - It Sorts an array of integerz in ascending
 *             order using Da heap sort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 *
 * Description: It Implementz da sift-down heap sort
 * algorithm. Prints da array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;

	for (m = (size / 2) - 1; m >= 0; m--)
		max_heapifyz(array, size, size, m);

	for (m = size - 1; m > 0; m--)
	{
		swap_intz(array, array + m);
		print_array(array, size);
		max_heapifyz(array, size, m, 0);
	}
}
