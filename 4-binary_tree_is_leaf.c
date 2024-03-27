#include "binary_trees.h"
/**
 * binary_tree_is_leaf - This function checks if a node is a leaf
 * @node: Target node
 * Return: 1 | 0 | NULL
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
return ((!node || node->left || node->right) ? 0 : 1);
}
