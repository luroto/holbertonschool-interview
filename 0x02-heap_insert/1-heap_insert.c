#include "binary_trees.h"
/**
 *heap_insert - Function to insert nodes in a Max heap
 *@root: Pointer to the entire structure
 *@value: Value to be added
 *Return: Pointer to the added node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int size, i, index;
	heap_t *newnode, *parent;

	if (*root == NULL)
	{
		newnode = binary_tree_node(*root, value);
		if (newnode == NULL)
			return (NULL);
		*root = newnode;
		return (*root);
	}
	i = size = binary_tree_size(*root) + 1;
	index = i / 2;
	parent = nthnode(root, index);
	newnode = binary_tree_node(parent, value);
	if (newnode == NULL)
		return (NULL);
	if (index * 2 == i)
		parent->left = newnode;
	else
		parent->right = newnode;
	if (i >= 2)
		while (newnode->parent != NULL && newnode->n > newnode->parent->n)
		{
			newnode->n = newnode->parent->n;
			newnode->parent->n = value;
			newnode = newnode->parent;
		}
	return (newnode);
}
/**
 * binary_tree_size - Calculates the number of nodes of a binary tree
 *@tree: pointer to the root of the tree
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t itera;

	itera = 0;
	if (tree != NULL)
	{
		itera = 1 +  binary_tree_size(tree->left) + binary_tree_size(tree->right);
	}
	return (itera);
}
/**
 *nthnode - Function to find the node for appending the new node
 *@root: Pointer to the entire structure
 *@index: Index for creating the path
 *Return: The node for appending the new node
 */
heap_t *nthnode(heap_t **root, int index)
{
	int path, mask;
	heap_t *aux;

	path = 0;
	aux = *root;
	while (1)
	{
		if ((1 << (path + 1)) > index)
			break;
		path++;
	}
	path--;
	while (path >= 0)
	{
		mask = (1 << path);
		if (index & mask)
			aux = aux->right;
		else
			aux = aux->left;
		path--;
	}
	return (aux);
}
