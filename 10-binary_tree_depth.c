#include "binary_trees.h"
/**
 * binary_tree_depth - Thid function measures the depth of a node in
 * a binary tree
 * @tree: Target node
 * Return: Depth | 0 if tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t x = 0;

if (!tree)
return (0);
while (tree->parent)
{
x++;
tree = tree->parent;
}
return (x);
}
