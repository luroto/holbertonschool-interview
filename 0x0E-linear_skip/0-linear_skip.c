#include "search.h"
/**
*linear_skip - function to perform a search in a linear skip
*@list: Head of the list
*@value: Integer to be searched
*Return: NULL if list is empty or value is not found,
*otherwise, pointer to the first occurrence of the value
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *preslist = NULL, *nextlist = NULL;
	size_t size, index, increment;

	size = listint_len(list);
	printf("%ld", size);
	increment = sqrt(size);
	preslist = list;
	nextlist = list->express;

	if (!list)
		return (NULL);
	while (nextlist->express != NULL)
	{
		printf("Value checked at index [%ld] = [%d]",
		       preslist->index, preslist->n);
		if (nextlist->n > value)
		{
			printf("Value found between indexes [%ld] and [%ld]",
				preslist->index, nextlist->index);
			while (preslist != NULL)
			{
				printf("Entro aqui\n");
				if (preslist->n == value)
					return (preslist);
				if (preslist->n > value || preslist->index == size - 1)
					return (NULL);
				preslist = preslist->next;
				index++;
			}
		}
		preslist = preslist->express;
		nextlist = nextlist->express;
		index += increment;
	}
	return (NULL);

}
/**
 *listint_len - returns the number of elements in a linked list
 *@h: pointer to the elements to be used as input
 *Return: The number of nodes as a result
*/
size_t listint_len(const skiplist_t *h)
{
	size_t contanodos = 0;

	if (h == NULL)
	{
		return (contanodos);
	}
	else
	{
		while (h != NULL)
		{
			h = h->next;
			contanodos++;
		}
	}
	return (contanodos);
}
