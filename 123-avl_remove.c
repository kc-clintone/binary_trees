#include "binary_trees.h"
/**
 * avl_remove - This function removes a node from a AVL tree
 * @root: Target's root
 * @value: Target node
 * Return: Target tree
*/
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *x = (avl_t *) brm((bst_t *) root, value);

if (x == NULL)
return (NULL);
balancer(&x);
return (x);
}
/**
 * fx - This function gets the next successor
 * @node: Target tree
 * Return: Minimum value of target tree
*/
int fx(bst_t *nd)
{
int x = 0;

if (nd == NULL)
return (0);
else
{
x = fx(nd->x);
if (x == 0)
{
return (nd->n);
}
return (x);
}
}
/**
 *rmt - This fn removes a node depending of its children
 *@root: Target node
 *Return: 0
*/
int rmt(bst_t *r)
{
int nv = 0;

if (!r->left && !r->right)
{
if (r->parent->right == r)
r->parent->right = NULL;
else
r->parent->left = NULL;
free(r);
return (0);
}
else if ((!r->left && r->right) || (!r->right && r->left))
{
if (!r->left)
{
if (r->parent->right == r)
r->parent->right = r->right;
else
r->parent->left = r->right;
r->right->parent = r->parent;
}
if (!r->right)
{
if (r->parent->right == r)
r->parent->right = r->left;
else
r->parent->left = r->left;
r->left->parent = r->parent;
}
free(r);
return (0);
}
else
{
nv = fx(r->right);
r->n = nv;
return (nv);
}
}
/**
 * balancer - This function measures the balance
 * factor for an AVL tree.
 * @tree: Target tree
 * Return: Factor
*/
void balancer(avl_t **t)
{
int val;

if (t == NULL || *t == NULL)
return;
if ((*t)->left == NULL && (*t)->right == NULL)
return;
balancer(&(*t)->left);
balancer(&(*t)->right);
val = binary_tree_balance((const binary_tree_t *)*t);
if (val > 1)
*t = binary_tree_rotate_right((binary_tree_t *)*t);
else if (val < -1)
*t = binary_tree_rotate_left((binary_tree_t *)*t);
}
/**
 * brm - This fn remove a node from a BST tree
 * @root: Target's root
 * @value: Target's value
 * Return: the tree changed
*/
bst_t *brm(bst_t *root, int value)
{
int x = 0;

if (root == NULL)
return (NULL);
if (value < root->n)
brm(root->left, value);
else if (value > root->n)
brm(root->right, value);
else if (value == root->n)
{
x = rmt(root);
if (x != 0)
brm(root->right, x);
}
else
return (NULL);
return (root);
}
