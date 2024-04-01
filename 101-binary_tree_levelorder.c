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
