#include "binary_trees.h"
/**
 * array_to_heap - This just builds a Max Binary Heap
 * tree from an array
 * @array: Pointrr to target
 * @size: Number of elements in array
 * Return: Pointer or NULL on failure
*/
heap_t *array_to_heap(int *array, size_t size)
{
unsigned int x;
heap_t *rt = NULL;

for (x = 0; x < size; x++)
heap_insert(&rt, array[x]);
return (rt);
}
