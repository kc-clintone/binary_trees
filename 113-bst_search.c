#include "binary_trees.h"
/**
 * bst_search - This function searches for a value in
 * a Binary Search Tree
 * @tree: A pointer to target tree
 * @value: Value to search
 * Return: A pointer , or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *temp_node = (bst_t *)tree;

if (!tree)
return (NULL);
while (temp_node)
{
if (value == temp_node->n)
return (temp_node);
if (value < temp_node->n)
temp_node = temp_node->left;
else if (value > temp_node->n)
temp_node = temp_node->right;
}
return (NULL);
}
