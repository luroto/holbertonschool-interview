#include "lists.h"
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Pointer to the entire linked list
 * Return: 1 if it is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	int j, val;
	listint_t *aux;

	if (*head == NULL)
		return (1);
	aux = *head;
	j = size_of_list(*head) - 1;
	while (aux != NULL)
	{
		val = get_value_by_index(*head, j);
		if (aux->n != val)
			return (0);
		j--;
		aux = aux->next;
	}
	return (1);
}
/**
 * get_value_by_index - Get the value of idx index
 * @head: Pointer to the head of the linked list
 * @idx: Index to be retrieved
 * Return: The value of the node
 */
int get_value_by_index(listint_t *head, int idx)
{
	int i = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		if (i == idx)
		{
			return (head->n);
		}
		i++;
		head = head->next;
	}
	return (0);
}
/**
 * size_of_list - Gets the size of a linked list
 * @head: Pointer to the first node
 * Return: The entire size
 */
int size_of_list(listint_t *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}
