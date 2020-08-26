#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Pointer to the entire linked list
 * Return: 1 if it is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	int size = 0, half = 0, pal = 1;

	if (*head == NULL)
		return (pal);
	size = size_list(*head);
	if (size == 1)
		return (pal);
	if (size == 2)
	{
		if ((*head)->n != (*head)->next->n)
			return (0);
		else
			return (pal);
	}
	half = size / 2;
	pal = checking_palindrome(1, size, half, *head);
	return (pal);
}
/**
 * size_list - Gets the size of a list
 * @head: pointer to the first node of the structure
 * Return: Number of nodes
 */
int size_list(listint_t *head)
{
	int i = 0;

	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}
/**
 *checking_palindrome -Recursive function that checks if a linked list is
 *palindrome
 *@start: Position of the first node to compare
 *@tail: Position of the last node to compare
 *@half: Position for the last node to be compared
 *@head: First node of the structure
 *Return: 1 if it is a palindrome, otherwise 0
 */
int checking_palindrome(int start, int tail, int half, listint_t *head)
{
	listint_t *aux = head;
	int j = 0, h = 0, t = 0;

	while (aux != NULL)
	{
		j++;
		if (j == start)
			h = aux->n;
		if (j == tail)
			t = aux->n;
		aux = aux->next;
	}
	if (t != h)
		return (0);
	if (start == half)
		return (1);
	return (checking_palindrome(start + 1, tail - 1, half, head));
}
