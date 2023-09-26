#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			temp = prev->prev;
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->prev = temp;
			if (temp != NULL)
				temp->next = current;
			else
				*list = current;
			current->next = prev;
			prev->prev = current;

			print_list(*list);
			prev = temp;
		}
		current = current->next;
	}
}
