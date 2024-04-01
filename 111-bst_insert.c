#include "binary_trees.h"
/**
 * bst_insert - This function inserts a value in
 * a Binary Search Tree
 * @tree: Double pointer to target tree
 * @value: Value to insert
 * Return: A pointer or NULL
*/
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *x = NULL, *y = NULL, *new = NULL;

if (!tree)
return (NULL);
if (*tree == NULL)
return (*tree = binary_tree_node(NULL, value));
x = *tree;
while (x)
{
y = x;
if (value < x->n)
x = x->left;
else if (value > x->n)
x = x->right;
else if (value == x->n)
return (NULL);
}
new = binary_tree_node(NULL, value);
if (y == NULL)
y = new;
else if (value < y->n)
{
y->left = new;
new->parent = y;
}
else
{
y->right = new;
new->parent = y;
}
return (new);
}
