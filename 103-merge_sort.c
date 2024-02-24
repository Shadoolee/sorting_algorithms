#include "sort.h"

void merge_subarrz(int *subarrz, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursivez(int *subarrz, int *buff, size_t front, size_t back);
void merge_sortz(int *array, size_t size);

/**
 * merge_subarrz - This Sort a subarray of integerz.
 * @subarrz: A subarray of an array of integerz to sort.
 * @buff: A buffer to store da sorted subarray.
 * @front: Da front index of da array.
 * @mid: Da middle index of da array.
 * @back: Da back index of da array.
 */
void merge_subarrz(int *subarrz, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t l, m, n = 0;

	printf("Merging...\n[left]: ");
	print_array(subarrz + front, mid - front);

	printf("[right]: ");
	print_array(subarrz + mid, back - mid);

	for (l = front, m = mid; l < mid && m < back; n++)
		buff[n] = (subarrz[l] < subarrz[m]) ? subarrz[l++] : subarrz[m++];
	for (; l < mid; l++)
		buff[n++] = subarrz[l];
	for (; m < back; m++)
		buff[n++] = subarrz[m];
	for (l = front, n = 0; l < back; l++)
		subarrz[l] = buff[n++];

	printf("[Done]: ");
	print_array(subarrz + front, back - front);
}

/**
 * merge_sort_recursivez - This Implement da merge sort algorithm
 * through recursion.
 * @subarrz: A subarray of an array of integerz to sort.
 * @buff: A buffer to store da sorted result.
 * @front: Da front index of da subarray.
 * @back: Da back index of da subarray.
 */
void merge_sort_recursivez(int *subarrz, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursivez(subarrz, buff, front, mid);
		merge_sort_recursivez(subarrz, buff, mid, back);
		merge_subarrz(subarrz, buff, front, mid, back);
	}
}

/**
 * merge_sort - This Sort an array of integerz in ascending
 * order using the merge sort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 *
 * Description: Implementz da top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursivez(array, buff, 0, size);

	free(buff);
}
