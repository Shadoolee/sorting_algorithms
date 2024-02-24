#include "sort.h"

void swap_node_aheadz(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behindz(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_aheadz - It Swap a node in a listint_t doubly-linked list
 *                   list of integerz with the node ahead of it.
 * @list: A pointer to da head of a doubly-linked list of integerz.
 * @tail: A pointer to da tail of the doubly-linked list.
 * @shaker: A pointer to da current swapping node of da cocktail shaker algo.
 */
void swap_node_aheadz(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behindz - It Swap a node in a listint_t doubly-linked
 *                    list of integerz with da node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to da tail of da doubly-linked list.
 * @shaker: A pointer to da current swapping node of da cocktail shaker algo.
 */
void swap_node_behindz(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - It Sorts a listint_t doubly-linked list of integerz in
 *                      ascending order using da cocktail shaker algorithm.
 * @list: A pointer to da head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirredz = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirredz == false)
	{
		shaken_not_stirredz = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_aheadz(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirredz = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behindz(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirredz = false;
			}
		}
	}
}
