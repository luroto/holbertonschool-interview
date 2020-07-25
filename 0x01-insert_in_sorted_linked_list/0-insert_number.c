#include "lists.h"
/**
 *insert_node - Insert node in a sorted linked list
 *@head: Entirle linked list
 *@number: Value to be added
 *Return: The added node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux, *newnode;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = number;
	if ((*head)->n > number)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	aux = *head;
	while (aux->next != NULL)
	{
		if (aux->next->n > number)
		{
			newnode->next = aux->next;
			aux->next = newnode;
			return (newnode);
		}
		aux = aux->next;
	}
	aux->next = newnode;
	return (newnode);
}
