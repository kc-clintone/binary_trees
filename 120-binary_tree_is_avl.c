#include "binary_trees.h"
/**
 * binary_tree_is_avl - This function determins if a binary tree
 * tree is an avl tree.
 * @tree: Pointer totarget tree
 * Return: 1 if trues, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (fn_4(tree, INT_MIN, INT_MAX));
}
/**
 * fn_4 - This function is just a helper for the above function
 * @t: Pointer to target tree
 * @x: minimum value
 * @y: maximum value
 * Return: 1 or 0
*/
int fn_4(const binary_tree_t *t, int x, int y)
{
int i, j;

if (!t)
return (1);
if (t->n < x || t->n > y)
return (0);
i = t->left ? 1 + binary_tree_height(t->left) : 0;
j = t->right ? 1 + binary_tree_height(t->right) : 0;
if (abs(i - j) > 1)
return (0);
return (fn_4(t->left, x, t->n - 1) && (t->right, t->n + 1, y));
}
/**
 * binary_tree_height - This function measures the height of a
 * binary tree
 * @t: Target tree
 * Return: Height
*/
size_t binary_tree_height(const binary_tree_t *t)
{
size_t hl = 0, hr = 0;

if (!t)
return (0);
hl = t->left ? 1 + binary_tree_height(t->left) : 0;
hr = t->right ? 1 + binary_tree_height(t->right) : 0;
return (hl > hr ? hl : hr);
}
