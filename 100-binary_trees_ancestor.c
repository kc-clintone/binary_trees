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
size_t df, ds;

if (!first || !second)
return NULL;
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
return ((binary_tree_t *)first);
first = first->parent;
second = second->parent;
}
return ((binary_tree_t *)first);
}
