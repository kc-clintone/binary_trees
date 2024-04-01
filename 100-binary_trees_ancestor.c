#include "binary_trees.h"
/**
 * binary_trees_ancestor - This function finds the lowest common
 * ancestor of two nodes
 * @first: Pointer to the first node to find the ancestor
 * @second: Pointer to the second node to find the ancestor
 * Return: Pointer to the ancestor node
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
size_t df, ds;

if (!first || !second)
return (NULL);

df = binary_tree_depth(first);
ds = binary_tree_depth(second);
while (df > ds)
{
first = first->parent;
df--;
}
while (ds > df)
{
second = second->parent;
ds--;
}
while (first && second)
{
if (first == second)
{
return ((binary_tree_t *)first);
first = first->parent;
second = second->parent;
}
}
return (NULL);
}

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
