#include "binary_trees.h"
/**
 * heap_to_sorted_array - This function converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: Pointer to the root of target
 * @size: Address to store size of array
 * Return: New array or NULL on failure
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int index, *arr = NULL;

if (!heap || !size)
return (NULL);
*size = ts(heap) + 1;
arr = malloc(sizeof(int) * (*size));
if (!arr)
return (NULL);
for (index = 0; heap; index++)
arr[index] = heap_extract(&heap);
return (arr);
}

/**
 * ts - This just helps the fn above
 * @tr: Pointer to target
 * Return: Height or 0
*/
size_t ts(const binary_tree_t *tr)
{
size_t hl = 0, hr = 0;

if (!tr)
return (0);
if (tr->left)
hl = 1 + ts(tr->left);
if (tr->right)
hr = 1 + ts(tr->right);
return (hl + hr);
}
