#include "lists.h"
/**
 *check_cycle - Check if there's a loop in a singly linked list
 *@list: First node of the structure
 *Return: 1 if there is a loop, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *slow_p, *fast_p;

	slow_p = list;
	fast_p = list;
	if (list == NULL)
		return (0);
	while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (1);
	}
	return (0);
}
