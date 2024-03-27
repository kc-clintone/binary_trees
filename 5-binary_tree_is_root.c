#include "binary_trees.h"
/**
 * binary_tree_is_root - This function checks if a node is a root
 * @node: Target node
 * Return: 1 | 0 | NULL
*/
int binary_tree_is_root(const binary_tree_t *node)
{
return ((!node || node->parent) ? 0 : 1);
}
