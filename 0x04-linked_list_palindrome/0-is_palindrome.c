#include "lists.h"

void reverse_list(listint_t **head);

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *turtle = *head, *hare = *head, *prev = NULL, *temp;
	listint_t *second_half, *first_half = *head;
	int palindrome = 1; /* list is a palindrome */

	if (*head == NULL || (*head)->next == NULL)
		return (palindrome);

	/* find the middle node of the list */
	while (hare != NULL && hare->next != NULL)
	{
		hare = hare->next->next;
		prev = turtle;
		turtle = turtle->next;
	}

	/* handle odd-length lists */
	if (hare != NULL) /* odd number of nodes */
	{
		second_half = turtle->next;
	}
	else /* even number of nodes */
	{
		second_half = turtle;
	}

	prev->next = NULL;
	reverse_list(&second_half);
	temp = second_half;

	/* compare the first half and second half of the list */
	while (first_half != NULL && second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			palindrome = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}
	reverse_list(&temp);
	prev->next = temp;

	return (palindrome);
}

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to pointer to the head of the list
 * Return: void
 */
void reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}
