#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Thif functjon checks if a binary
 * tree is perfect
 * @tree: Pointer to root node of the target tree
 * Return: 1 or 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t x = 0, n = 0, p = 0;

if (!tree)
return (0);
if (!tree->right && !tree->left)
return (1);
x = binary_tree_height(tree);
n = binary_tree_size(tree);
p = (size_t)pwr_r(2, x + 1);
return (p - 1 == n);
}
/**
 * binary_tree_height - This function measures the height of a binary tree
 * @tree: Target tree
 * Return: Height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t hl, hr = 0;

if (!tree)
return (0);
hl = tree->left ? 1 + binary_tree_height(tree->left) : 0;
hr = tree->right ? 1 + binary_tree_height(tree->right) : 0;
return (hl > hr ? hl : hr);
}
/**
 * binary_tree_size - This function measures the size of a binary tree
 * @tree: Target tree
 * Return: Size or NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * pwr_r - This function returns the value of n raised to
 * the power of p
 * @n: Target value
 * @p: Power
 * Return: n
*/
int pwr_r(int n, int p)
{
if (p < 0)
return (-1);
if (p == 0)
return (1);
else
return (n *pwr_p(n, p - 1));
}
