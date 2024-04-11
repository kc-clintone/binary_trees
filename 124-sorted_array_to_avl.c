#include "binary_trees.h"
/**
 * sorted_array_to_avl - This function builds an AVL tree
 * from an array
 * @array: Pointer to the first element of the array
 * to be converted
 * @size: Number of elements in the array
 * Return: Pointer or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *t = NULL;
size_t c;

if (!array)
return (NULL);
c = (size - 1) / 2;
t = binary_tree_node(NULL, array[c]);
fn_5(&t, array, -1, c);
fn_5(&t, array, c, size);
return (t);
}
/**
 * fn_5 - This just helps the above funtion to build
 * an AVL tree from an array
 * @r: Pointer to the root node of target
 * @arr: Pointer to the first element of the array
 * @x: lower bound index
 * @y: upper bound index
*/
void fn_5(avl_t **r, int *arr, size_t x, size_t y)
{
avl_t *new = NULL;
size_t c;

if (y - x > 1)
{
c = (y - x) / 2 + x;
new = binary_tree_node(*r, arr[c]);
if (arr[c] > (*r)->n)
(*r)->right = new;
else if (arr[c] < (*r)->n)
(*r)->left = new;
fn_5(&new, arr, x, c);
fn_5(&new, arr, c, y);
}
}
