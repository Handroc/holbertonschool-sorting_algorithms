#include "sort.h"
/**
 * sort_nodes - Sorts two adjacent nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: The first node to be sorted
 * @node2: The second node to be sorted
 */
void sort_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;
	
	node2->prev = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_node, *current, *compare;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		new_node = current->next;
		compare = current->prev;

		while (compare && compare->n > current->n)
		{
			sort_nodes(list, compare, current);

			print_list(*list);

			compare = current->prev;
		}
		current = new_node;
	}
}
