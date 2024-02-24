#include "sort.h"

/**
 * swap_nodes - It swap two nodez in a listint_t doubly-linked listz.
 * @h: A pointer to da head of da doubly-linked list.
 * @n1: A pointer to da first node to swapz.
 * @n2: The second node to swapz.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - It sortz a doubly linked list of integerz
 *                       uzing da insertion sort algorithm.
 * @list: A pointer to da head of a doubly-linked list of integerz.
 *
 * Description: Printz the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
