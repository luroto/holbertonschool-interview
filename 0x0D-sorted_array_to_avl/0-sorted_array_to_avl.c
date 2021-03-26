#include "binary_trees.h"
/**
*sorted_array_to_avl - Function to create a AVL BT based on a sorted array
*@array: array of integers to be placed in the AVL
*@size: Size of the array
*Return: an AVL Node
**/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl;

	if (array == NULL || size == 0)
		return (NULL);

	avl = inserting_avl_node(array, 0, size - 1, NULL);
	return (avl);

}

/**
*inserting_avl_node - Function for creating an AVL tree based on a sorted array
*@array: Source array of integers
*@first: first position of the array
*@last: last position of the array
*@root: root node of the AVL or NULL if hasn't been created
*Return: A full tree
*/
avl_t *inserting_avl_node(int *array, size_t first, size_t last, avl_t *root)
{
	size_t midi;
	avl_t *nuevo_nodo;

	if (first > last)
		return (NULL);

	midi = (first + last) / 2;
	nuevo_nodo = new_avl_node(root, array[midi]);

	if (nuevo_nodo == NULL)
		return (NULL);

	if (midi != first)
		nuevo_nodo->left = inserting_avl_node(array, first, midi - 1, nuevo_nodo);
	if (midi != last)
		nuevo_nodo->right = inserting_avl_node(array, midi + 1, last, nuevo_nodo);

	return (nuevo_nodo);
}

/**
*new_avl_node- Creates a new AVL node and links it with its parent
*@root: Parent of the new node
*@data: Integer to be inserted
*Return: The new node
*/
avl_t *new_avl_node(avl_t *root, int data)
{
	avl_t *nuevito;

	nuevito = malloc(sizeof(avl_t));

	if (nuevito == NULL)
		return (NULL);
	nuevito->n = data;
	nuevito->left = NULL;
	nuevito->right = NULL;
	nuevito->parent = root;

	return (nuevito);
}
