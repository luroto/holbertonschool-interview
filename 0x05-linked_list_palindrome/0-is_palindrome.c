#include "lists.h"
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Pointer to the entire linked list
 * Return: 1 if it is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *h = NULL, *aux = NULL, *aux2 = NULL;
	int size = 0, half = 0, i = 0, pal = 1;

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
	aux = *head;
	while (i < half)
	{
		i++;
		add_node_at_head(&h, aux->n);
		aux = aux->next;
	}
	if (size % 2 != 0)
		aux = aux->next;
	aux2 = h;
	while (aux != NULL)
	{
		if (aux->n != aux2->n)
			pal = 0;
		aux = aux->next;
		aux2 = aux2->next;
	}
	free_listint(h);
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
 * add_node_at_head - add nodes from the original list as stack
 * @head: Structure of the stack
 * @n: Number to be added
 *Return: The created node
 */
listint_t *add_node_at_head(listint_t **head, int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;
	return (*head);
}
