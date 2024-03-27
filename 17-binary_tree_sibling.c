#include "binary_trees.h"
/**
 * binary_tree_sibling - This function finds the sibling of a node
 * @node: Pointer to the target node
 * Return: Pointer to sibling node or NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (!node || !node->parent)
return (NULL);
if (node == node->parent->left)
return (node->parent->right);
return (node->parent->left);
}
