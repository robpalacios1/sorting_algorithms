#include "sort.h"
/**
 *insertion_sort_list - function that sorts a doubly linked list
 *of integers in ascending order
 *@list: pointer to list doubly linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list))
	{
		return;
	}
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}

			current->next = current->prev;
			current->prev = current->next->prev;

			if (current->prev != NULL)
			{
				current->prev->next = current;
			}
			else
			{
				*list = current;
			}
			current->next->prev = current;
			print_list(*list);
		}
		current = temp;
	}
}
