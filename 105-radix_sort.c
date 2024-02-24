#include "sort.h"

int get_maxz(int *array, int size);
void radix_counting_sortz(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_maxz - It Get da maximum value in an array of integerz.
 * @array: An array of integerz.
 * @size: Da size of da array.
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
 * radix_counting_sortz - It Sortz da significant digitz of an array of
 * integerz in ascending order using da counting sort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 * @sig: Da significant digit to sort on.
 * @buff: A buffer to store da sorted array.
 */
void radix_counting_sortz(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t m;

	for (m = 0; m < size; m++)
		count[(array[m] / sig) % 10] += 1;

	for (m = 0; m < 10; m++)
		count[m] += count[m - 1];

	for (m = size - 1; (int)m >= 0; m--)
	{
		buff[count[(array[m] / sig) % 10] - 1] = array[m];
		count[(array[m] / sig) % 10] -= 1;
	}

	for (m = 0; m < size; m++)
		array[m] = buff[m];
}

/**
 * radix_sort - It Sortz an array of integerz in ascending
 * order using da radix sort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 *
 * Description: It Implementz da LSD radix sort algorithm. Printz
 * da array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxz, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxz = get_maxz(array, size);
	for (sig = 1; maxz / sig > 0; sig *= 10)
	{
		radix_counting_sortz(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
