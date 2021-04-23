#ifndef _SORT_H_
#define _SORT_H_
#include <stdlib.h>
void print_array(const int *array, size_t size);
void building_heap(int *array, int size, int index);
void swapping(int *a, int *b);
void heap_sort(int *array, size_t size);
#endif
