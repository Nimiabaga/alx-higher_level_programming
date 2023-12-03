#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	int arr[1000]; /* Assuming a maximum size for the array */
	int i, j;
	int length = 0;

	listint_t *current = *head;

	if (current == NULL)
		return (1);

	/* Store the values of the linked list in the array */
	while (current != NULL)
	{
		arr[length] = current->n;
		current = current->next;
		length++;
	}

	for (i = 0, j = length - 1; i < length / 2; i++, j--)
	{
		if (arr[i] != arr[j])
			return (0);
	}

	return (1);
}
