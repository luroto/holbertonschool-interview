#ifndef LISTS_H
#define LISTS_H
#include <stdlib.h>
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @next: points to the next node
 * @prev: points to the previous node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *next;
	struct dlistint_s *prev;
} dlistint_t;
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
int is_palindrome(listint_t **head);
dlistint_t *add_node_in_dlist(dlistint_t **head, int n);
void free_dlist(dlistint_t *h);
#endif /* LISTS_H */
