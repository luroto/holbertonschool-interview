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

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = number;
	if (head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
		return (newnode);
	}

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
			if (aux->next->next != NULL)
				newnode->next = aux->next;
			aux->next = newnode;
			return (newnode);
		}
		aux = aux->next;
	}
	aux->next = newnode;
	newnode->next = NULL;
	return (newnode);
}
