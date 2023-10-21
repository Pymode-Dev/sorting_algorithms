#include "sort.h"


/**
 * swap_nodes - This swap nodes in a doubly linked list
 * @head: the head node of the doubly linked list
 * @node1: the first node
 * @node2: the second node
 * Return: void
 */

void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = (*node1);

	node2->prev = (*node1)->prev;
	node2->next = (*node1);

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		(*head) = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly liked list of int in ascending using
 * insertion sort
 * @list: the pointer to pointer
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *nptr, *pptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;



	for (ptr = (*list)->next; ptr != NULL; ptr = pptr)
	{
		pptr = ptr->next;
		nptr = ptr->prev;

		while (nptr != NULL && (ptr->n < nptr->n))
		{
			swap_nodes(list, &nptr, ptr);
			print_list((const listint_t *)*list);
		}
	}
}
