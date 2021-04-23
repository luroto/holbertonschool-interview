#include "sort.h"
/**
*building_heap - Function for building a heap
*@array: Array of integers to be sorted
*@size: Size of the array
*@index: Index of root in the array
*/
void building_heap(int *array, int size, int index)
{
	int max, left, right;

	max = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < size && array[left] > array[max])
		max = 1;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != index)
	{
		swapping(&array[index], &array[max]);
		print_array(array, size);
		building_heap(array, size, max);
	}
}

/**
*swapping - function for swapping places on an array
*@a: first array slot to be swapped
*@b: second array slot to be swapped
*/
void swapping(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;

}
/**
*heap_sort - main function for sorting an array via heapSort
*@array: array to be created
*@size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		building_heap(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swapping(&array[0], &array[i]);
		building_heap(array, i, 0);
	}

}
