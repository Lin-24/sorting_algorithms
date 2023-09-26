#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: Pointer to the first node to be swapped.
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev, *temp_next;

	temp_prev = node1->prev;
	temp_next = node2->next;

	if (temp_prev != NULL)
		temp_prev->next = node2;

	node1->prev = node2;
	node1->next = temp_next;

	if (temp_next != NULL)
		temp_next->prev = node1;

	node2->prev = temp_prev;
	node2->next = node1;

	if (node1->next != NULL)
		node1->next->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;
	listint_t *left = NULL;
	listint_t *right = NULL;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		current = *list;
		
		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		right = current;

		if (swapped == 0)
			break;

		swapped = 0;
		current = right;

		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

		left = current;

	} while (swapped);
}
