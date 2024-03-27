#include "binary_trees.h"
/**
 * binary_tree_uncle - This function finds the uncle 🤣 of a node
 * @node: Pointer to the target node
 * Return: pointer to the uncle node 🤭
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (!node || !node->parent)
return (NULL);
return (binary_tree_sibling(node->parent));
}
/**
 * binary_tree_sibling - This function finds the sibling of a node
 * @node: Pointer to the tatget node
 * Return: Pointer to the sibling node
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (!node || !node->parent)
return (NULL);
if (node == node->parent->left)
return (node->parent->right);
return (node->parent->left);
}
