#include "binary_trees.h"
/**
 *binary_tree_node - create a node for a binary tree
 *@parent: pointer for the structure
 *@value: Value to be inserted
 *Return: Pointer to the created node or NULL if it failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnodo;

	newnodo = malloc(sizeof(binary_tree_t));
	if (newnodo == NULL)
		return (NULL);
	newnodo->n = value;
	newnodo->parent = NULL;
	newnodo->left = NULL;
	newnodo->right = NULL;

	if (parent == NULL)
	{
		parent = newnodo;
		return (newnodo);
	}
	newnodo->parent = parent;
	return (newnodo);
}
