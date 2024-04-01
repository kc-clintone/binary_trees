#include "binary_trees.h"
/**
 * binary_tree_levelorder - This function traverses a binary tree using
 * level-order traverse
 * @tree: Target tree
 * @func: Pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
size_t l, ml;

if (!tree || !func)
return;
ml = binary_tree_height(tree) + 1;
for (l = 1; l <= ml; l++)
fn_1(tree, func, l);
}
/**
 * binary_tree_height - Thif function measures the height of a binary tree
 * @tree: Target tree
 * Return: Height | 0 if tree is NULL
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
 * fn_1 - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void fn_1(const binary_tree_t *tree, void (*func)(int), size_t level)
{
if (level == 1)
func(tree->n);
else
{
fn_1(tree->left, func, level - 1);
fn_1(tree->right, func, level - 1);
}
}
