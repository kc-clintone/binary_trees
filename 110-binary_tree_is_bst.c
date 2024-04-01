#include "binary_trees.h"
/**
 * binary_tree_is_bst - This function checks if a binary tree is
 * a valid Binary Search Tree
 * @tree: A pointer to target tree
 * Return: 1 if true, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (fn_3(tree, INT_MIN, INT_MAX));
}
/**
 * fn_3 - This function checks if a binary tree is
 * a valid Binary Search Tree
 * @tree: Pointer to target tree
 * @x: Minimum point of checks
 * @y: Maximum points of checks
 * Return: 1, 0 otherwise
*/
int fn_3(const binary_tree_t *tree, int x, int y)
{
if (!tree)
return (1);
if (tree->n < x || tree->n > y)
return (0);
return (fn_3(tree->left, x, tree->n - 1) &&
fn_3(tree->right, tree->n + 1, y));
}
