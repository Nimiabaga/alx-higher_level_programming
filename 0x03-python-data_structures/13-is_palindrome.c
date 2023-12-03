#include "lists.h"
int is_palindrome(listint_t **head);


/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * @head: Pointer to the head of the list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *runner = *head, *walker = *head, *second_half = *head;
	listint_t *reversed_half = NULL;

	/* Check for empty list or single-node list (palindrome) */
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	/* Move runner to the end and walker to the middle of the list */
	while (1)
	{
		runner = runner->next->next;
		if (!runner)
		{
			reversed_half = walker->next;
			break;
		}
		if (!runner->next)
		{
			reversed_half = walker->next->next;
			break;
		}
		walker = walker->next;
	}

	/* Reverse the second half of the list */
	moveback_listint(&reversed_half);

	/* Compare the first and reversed second half of the list */
	while (reversed_half && second_half)
	{
		if (second_half->n == reversed_half->n)
		{
			reversed_half = reversed_half->next;
			second_half = second_half->next;
		}
		else
			return (0);
	}

	/* If reversed_half is NULL, the list is a palindrome */
	if (!reversed_half)
		return (1);

	return (0);
}

/**
 * reverse_listint - Reverses the direction of a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
void reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *current = *head;
	listint_t *next_node = NULL;

	while (current)
	{
		next_node = current->next;
		current->next = previous;
		previous = current;
		current = next_node;
	}

	*head = previous;
}
