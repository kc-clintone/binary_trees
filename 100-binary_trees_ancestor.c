#include "binary_trees.h"
/**
 * binary_trees_ancestor - This function finds the lowest common
 * ancestor of two nodes
 * @first: Pointer to the first node to find the ancestor
 * @second: Pointer to the second node to find the ancestor
 * Return: pointer to ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
size_t fd, sd;

if (!first || !second)
return NULL;
fd = binary_tree_depth(first);
sd = binary_tree_depth(second);
for (; fd > sd; fd--)
first = first->parent;
for (; sd > fd; sd--)
second = second->parent;
for (; first && second && first != second;)
{
first = first->parent;
second = second->parent;
}
return (first ? (binary_tree_t *)first : NULL);
}
/**
 * binary_tree_depth - This function measures the depth of a node
 * in a binary tree
 * @tree: Target node
 * Return: depth
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
