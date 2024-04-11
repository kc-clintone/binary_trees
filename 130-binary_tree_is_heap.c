#include "binary_trees.h"
/**
 * binary_tree_is_heap - This function
 * checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of target
 * Return: 1 or 0
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (fn_6(tree));
}

/**
 * fn_6 - A helper for the fn above
 * @tr: Pointer target
 * Return: 1 or 0
*/
int fn_6(const binary_tree_t *tr)
{
if (!tr)
return (1);
if (!btc(tr))
return (0);
if (tr->left)
if (tr->left->n > tr->n)
return (0);
if (tr->right)
if (tr->right->n > tr->n)
return (0);
return (fn_6(tr->left) &&
fn_6(tr->right));
}
/**
 * bts - This only measures the size of a binary tree
 * @tr: Targrt
 * Return: Size or 0
*/
size_t bts(const binary_tree_t *tr)
{
if (!tr)
return (0);
return (bts(tr->left) + bts(tr->right) + 1);
}
/**
 * fn_7 - Just a helper
 * @tr: Pointer to target tree
 * @i: Target node index
 * @x: Nodes in the tree
 * Return: 1 or 0
*/
int fn_7(const binary_tree_t *tr, size_t i, size_t x)
{
if (!tr)
return (1);
if (i >= x)
return (0);
return (fn_7(tr->left, 2 * i + 1, x) && fn_7(tr->right, 2 * i + 2, x));
}
/**
 * btc - This function checks if a binary tree is complete
 * @tr: Pointer to target tree
 * Return: 1 or 0
*/
int btc(const binary_tree_t *tr)
{
size_t x;

if (!tr)
return (0);
x = bts(tr);
return (fn_7(tr, 0, x));
}
