#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: Pointer to the entire linked list
 * Return: 1 if it is a palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	dlistint_t *h, *auxd;
	listint_t *aux;

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
	while (auxd != NULL)
		auxd = auxd->next;	
	while (auxd != NULL && aux != NULL)
	{
		if (auxd->n != aux->n)
			return (0);
		auxd = auxd->prev;
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
dlistint_t *add_node_in_dlist(dlistint_t **head, int n)
{
	dlistint_t *newnode, *aux;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (*head);
	}
	aux = *head;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = newnode;
	newnode->prev = aux;
	return (newnode);
}
/**
 * free_dlist - free a doubly linked list
 * @h: Pointer to the first node
 * Return: It's a void function
 */
void free_dlist(dlistint_t *h)
{
	dlistint_t *aux;

	while (h != NULL)
	{
		aux = h->next;
		free(h);
		h = aux;
	}
}
