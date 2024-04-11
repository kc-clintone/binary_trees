#include "binary_trees.h"
/**
 * inode - This function inserts a node value into an AVL.
 * @t: Pointer to target node
 * @p: Parent node
 * @new: Pointer to left or right insertion.
 * @val: Target value.
 * Return: Pointer to new root after insertion otherwise NULL
*/
avl_t *inode(avl_t **t, avl_t *p, avl_t **new, int val)
{
int b;

if (*t == NULL)
return (*new = binary_tree_node(p, val));
if ((*t)->n > val)
{
(*t)->left = inode(&(*t)->left, *t, new, val);
if ((*t)->left == NULL)
return (NULL);
}
else if ((*t)->n < val)
{
(*t)->right = inode(&(*t)->right, *t, new, val);
if ((*t)->right == NULL)
return (NULL);
}
else
{
return (*t);
}
b = binary_tree_balance(*t);
if (b > 1 && (*t)->left->n > val)
{
*t = binary_tree_rotate_right(*t);
}
else if (b > 1 && (*t)->left->n < val)
{
(*t)->left = binary_tree_rotate_left((*t)->left);
*t = binary_tree_rotate_right(*t);
}
else if (b < -1 && (*t)->right->n < val)
{
*t = binary_tree_rotate_left(*t);
}
else if (b < -1 && (*t)->right->n > val)
{
(*t)->right = binary_tree_rotate_right((*t)->right);
*t = binary_tree_rotate_left(*t);
}
return (*t);
}
/**
 * avl_insert - This function inserts a value into an AVL tree.
 * @tree: The pointer to root node.
 * @value: The value to store.
 * Return: Node, or NULL.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new = NULL;

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
inode(tree, *tree, &new, value);
return (new);
}
