#include "sort.h"

/**
 * get_maxz - It Get da maximum value in an array of integerz.
 * @array: An array of integerz.
 * @size: Da size of the array.
 *
 * Return: Da maximum integer in da array.
 */
int get_maxz(int *array, int size)
{
	int maxz, m;

	for (maxz = array[0], m = 1; m < size; m++)
	{
		if (array[m] > maxz)
			maxz = array[m];
	}

	return (maxz);
}

/**
 * counting_sort - It Sortz an array of integers in ascending order
 *                 using da counting sort algorithm.
 * @array: An array of integers.
 * @size: Da size of da array.
 *
 * Description: Printz da counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxz, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxz = get_maxz(array, size);
	count = malloc(sizeof(int) * (maxz + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (maxz + 1); m++)
		count[m] = 0;
	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;
	for (m = 0; m < (maxz + 1); m++)
		count[m] += count[m - 1];
	print_array(count, maxz + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[count[array[m]] - 1] = array[m];
		count[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(count);
}
