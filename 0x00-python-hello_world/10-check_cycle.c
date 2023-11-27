#include "lists.h"

/**
 * check_cycle - Checks if a linked list contains a cycle
 * @head: Pointer to the head of the linked list
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *head)
{
	listint_t *slow_ptr; /* Pointer to move one node at a time */
	listint_t *fast_ptr; /* Pointer to move two nodes at a time */

	/* Check for an empty list or a list with only one node */
	if (head == NULL || head->next == NULL)
		return (0); /* No cycle found */

	/* Initialize pointers to the second and third nodes of the list */
	slow_ptr = head->next;
	fast_ptr = head->next->next;

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		/* If the pointers meet, a cycle is detected */
		if (slow_ptr == fast_ptr)
			return (1); /* Cycle detected */
	}

	return (0); /* No cycle found */
}

