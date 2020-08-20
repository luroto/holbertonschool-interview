#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Pointer to the entire linked list
 * Return: 1 if it is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *h, *auxd, *aux;

	if (*head == NULL)
		return (1);
	h = NULL;
	aux = *head;
	while (aux != NULL)
	{
		add_node_in_dlist(&h, aux->n);
		aux = aux->next;
	}
	aux = *head;
	auxd = h;
	while (auxd != NULL && aux != NULL)
	{
		if (auxd->n != aux->n)
			return (0);
		auxd = auxd->next;
		aux = aux->next;
	}
	free_dlist(h);
	return (1);
}
/**
 * add_node_in_dlist - insert node in doubly linked list
 * @head: Pointer to the entire strucure
 * @n: Value to be inserted in the new node
 * Return: Newnode, otherwise NULL
 */
listint_t *add_node_in_dlist(listint_t **head, int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = *head;
	if (*head != NULL)
		(*head)->next = newnode;
	*head = newnode;
	return (newnode);
}
/**
 * free_dlist - free a doubly linked list
 * @h: Pointer to the first node
 * Return: It's a void function
 */
void free_dlist(listint_t *h)
{
	listint_t *aux;

	while (h != NULL)
	{
		aux = h->next;
		free(h);
		h = aux;
	}
}
