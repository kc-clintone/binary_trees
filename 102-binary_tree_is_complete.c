#include "binary_trees.h"
/**
 * binary_tree_is_complete - This function checks if a binary tree
 * is complete
 * @tree: A pointer to target tree
 * Return: 1, 0 or NULL
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
size_t x;
if (!tree)
return (0);
x = binary_tree_size(tree);
return (fn_2(tree, 0, x));
}
/**
 * binary_tree_size - This function measures the size of a binary tree
 * @tree: Target tree
 * Return: Size, 0 or NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (binary_tree_size(tree->left) +
binary_tree_size(tree->right) + 1);
}
/**
 * fn_2 - Thid function checks if a binary tree is complete
 * @tree: A pointer to target tree
 * @x: Target node
 * @s: Nodes
 * Return: 1, 0 or NULL
*/
int fn_2(const binary_tree_t *tree, size_t x, size_t s)
{
if (!tree)
return (1);
if (x >= s)
return (0);
return (fn_2(tree->left, 2 * x + 1, s) &&
fn_2(tree->right, 2 * x + 2, s));
}
