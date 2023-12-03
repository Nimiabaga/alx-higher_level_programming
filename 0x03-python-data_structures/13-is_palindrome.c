#include "lists.h"

/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the new head of the reversed list
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

/**
 * is_palindrome - Checks if a linked list is a palindrome
 * @head: Pointer to the head of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half = *head;
	listint_t *copy = NULL;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (1)
	{
		fast = fast->next->next;
		if (!fast)
		{
			copy = slow->next;
			break;
		}
		if (!fast->next)
		{
			copy = slow->next->next;
			break;
		}
		slow = slow->next;
	}

	reverse_listint(&copy);

	while (copy && second_half)
	{
		if (second_half->n == copy->n)
		{
			copy = copy->next;
			second_half = second_half->next;
		}
		else
			return (0);
	}

	if (!copy)
		return (1);
	return (0);
}

