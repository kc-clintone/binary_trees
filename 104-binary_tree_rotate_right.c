#include "binary_trees.h"
/**
 * binary_tree_rotate_right - This function rotates a tree right
 * @tree: Target tree
 * Return: New node
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *tp;

if (tree == NULL || tree->left == NULL)
return (NULL);
tp = tree->left;
tree->left = tp->right;
if (tp->right != NULL)
tp->right->parent = tree;
tp->right = tree;
tp->parent = tree->parent;
tree->parent = tp;
return (tp);
}
