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
	skiplist_t *preslist;

	if (list == NULL)
	return (NULL);
	preslist = list;

	while (preslist != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			preslist->index, preslist->n);
		if (preslist != NULL && preslist->express != NULL &&
			preslist->express->n >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				preslist->index, preslist->express->index);
			break;
		}

		if (preslist->express->express == NULL && preslist->express->n < value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				preslist->index, preslist->express->index);
			break;
		}
		preslist = preslist->express;
	}
	while (preslist != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			preslist->index, preslist->n);
		if (preslist->n == value)
			return (preslist);
		preslist = preslist->next;
	}
	return (NULL);
}
