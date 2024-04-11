#include "binary_trees.h"
/**
 * array_to_avl - This function builds an AVL tree from an array
 * @array: Target array
 * @size: Size of array
 * Return: Pointer or NULL on fail
*/
avl_t *array_to_avl(int *array, size_t size)
{
unsigned int x; avl_t *y = NULL;

for (x = 0; x < size; x++)
avl_insert(&y, array[x]);
return (y);
}
