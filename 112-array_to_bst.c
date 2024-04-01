#include "binary_trees.h"
/**
 * array_to_bst - This function builds
 * a Binary Search Tree from an array
 * @array: Pointer to target element
 * @size: Number of elements
 * Return: A pointer or NULL
*/
bst_t *array_to_bst(int *array, size_t size)
{
unsigned int x;
bst_t *target = NULL;

for (x = 0; ilx < size; x++)
bst_insert(&target, array[i]);
return (target);
}
