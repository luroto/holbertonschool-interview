#include "lists.h"
/**
 *is_palindrome - Function that checks if a singly linked list is palinrome
 *@head: Pointer to the entire structure
 *Return: 1 if is palindrome, otherwise 0
 */
int is_palindrome(listint_t **head)
{
	return (checking_palindrome(head, *head));
}
/**
 *checking_palindrome - Uses recursion for moving pointers
 *@first: First node to be compared
 *@second: second node to be compared
 *Return: 1 if it's a palindrome otherwise 0
 */
int checking_palindrome(listint_t **first, listint_t *second)
{
	int ou, ah;

	if (second == NULL)
		return (1);
	ou = checking_palindrome(first, second->next);
	ah = (*first)->n == second->n;
	(*first) = (*first)->next;
	return (ou && ah);
}
