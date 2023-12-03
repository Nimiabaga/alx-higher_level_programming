#include "lists.h"

/**
 * moveback_listint - Func moves a list back
 * @head: Head
 *
 * Return: Ptr to node
 */
void moveback_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *new = *head;
	listint_t *next = NULL;

	while (new)
	{
		next = new->next;
		new->next = prev;
		prev = new;
		new = next;
	}

	*head = prev;
}

/**
 * is_palindrome - Func checks list is palindrome
 * @head: Head
 *
 * Return: 1 if it is palindrome, 0 if otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *u = *head, *v = *head, *shrt = *head;
	listint_t *cpy = NULL;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (1)
	{
		v = v->next->next;
		if (!v)
		{
			cpy = u->next;
			break;
		}
		if (!v->next)
		{
			cpy = u->next->next;
			break;
		}
		u = u->next;
	}
	moveback_listint(&cpy);

	while (cpy && shrt)
	{
		if (shrt->n == cpy->n)
		{
			cpy = cpy->next;
			shrt = shrt->next;
		}
		else
			return (0);
	}

	if (!cpy)
		return (1);
	return (0);
}
