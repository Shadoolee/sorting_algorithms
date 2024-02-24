/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_intz(int *a, int *b);
void bitonic_mergez(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seqz(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_intz - It Swap two integerz in an array.
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
 * bitonic_mergez - It Sortz a bitonic sequence inside an array of integerz.
 * @array: An array of integerz.
 * @size: Da size of da array.
 * @start: Da starting index of da sequence in array to sort.
 * @seq: Da size of da sequence to sort.
 * @flow: Da direction to sort in.
 */
void bitonic_mergez(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t m, jump = seq / 2;

	if (seq > 1)
	{
		for (m = start; m < start + jump; m++)
		{
			if ((flow == UP && array[m] > array[m + jump]) ||
			    (flow == DOWN && array[m] < array[m + jump]))
				swap_intz(array + m, array + m + jump);
		}
		bitonic_mergez(array, size, start, jump, flow);
		bitonic_mergez(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seqz - It Convert an array of integerz into a bitonic sequence.
 * @array: An array of integerz.
 * @size: Da size of da array.
 * @start: Da starting index of a block of building bitonic sequence.
 * @seq: Da size of a block of da building bitonic sequence.
 * @flow: Da direction to sort da bitonic sequence block in.
 */
void bitonic_seqz(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seqz(array, size, start, cut, UP);
		bitonic_seqz(array, size, start + cut, cut, DOWN);
		bitonic_mergez(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - It Sortz an array of integerz in ascending
 * order using da bitonic sort algorithm.
 * @array: An array of integerz.
 * @size: Da size of da array.
 *
 * Description: It Printz da array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seqz(array, size, 0, size, UP);
}
