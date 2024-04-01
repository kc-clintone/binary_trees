#include "binary_trees.h"
/**
 * bt_height - This function measures height of a binary
 * tree for a balanced tree
 * @tree: Target tree
 * Return: Height
*/
size_t bt_height(const binary_tree_t *tree)
{
size_t i = 0, j = 0;

if (tree == NULL)y

return (0);
else
{
if (tree)
{
i = tree->left ? 1 + bt_height(tree->left) : 1;
j = tree->right ? 1 + bt_height(tree->right) : 1;
}
return ((i > j) ? i : j);
}
}
/**
 * binary_tree_balance - This function  that measures the balance
 * factor of a binary tree
 * @tree: Target tree
 * Return: Balanced factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
int x = 0, y = 0, z = 0;

if (tree)
{
y = ((int)bt_height(tree->left));
x = ((int)bt_height(tree->right));
z = y - x;
}
return (z);
}
