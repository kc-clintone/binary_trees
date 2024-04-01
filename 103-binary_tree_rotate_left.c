#include "binary_trees.h"
/**
 * binary_tree_rotate_left - This function rotates tree left
 * @tree: Target tree
 * Return: New node
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *tp;

if (tree == NULL || tree->right == NULL)
return (NULL);
tp = tree->right;
tree->right = tp->left;
if (tp->left != NULL)
tp->left->parent = tree;
tp->left = tree;
tp->parent = tree->parent;
tree->parent = tp;
return (tp);
}
