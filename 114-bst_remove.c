#include "binary_trees.h"
/**
 * bst_remove - This function remove a node from a BST tree
 * @root: Root of tree
 * @value: Node with target
 * Return: Target tree
*/
bst_t *bst_remove(bst_t *root, int value)
{
int kind = 0;

if (root == NULL)
return (NULL);
if (value < root->n)
bst_remove(root->left, value);
else if (value > root->n)
bst_remove(root->right, value);
else if (value == root->n)
{
kind = clean_up(root);
if (kind != 0)
bst_remove(root->right, kind);
}
else
return (NULL);
return (root);
}

/**
 * next_of_kin - I didn't get a better name lol 😂
 * @node: Target tree
 * Return: Min value of tree
*/
int next_of_kin(bst_t *node)
{
int x = 0;

if (node == NULL)
return (0);
else
{
x = next_of_kin(node->x);
if (x == 0)
return (node->n);
return (x);
}
}
/**
 *clean_up - Does some cleanup
 *@node: Target node
 *Return: 0, or 1
*/
int clean_up(bst_t *node)
{
if (!node->left && !node->right)
{
if (node->parent->right == node)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
return (0);
}
else if ((!node->left && node->right)
|| (!node->right && node->left))
{
if (!node->left)
{
if (node->parent->right == node)
node->parent->right = node->right;
else
node->parent->left = node->right;
node->right->parent = node->parent;
}
if (!node->right)
{
if (node->parent->right == node)
node->parent->right = node->left;
else
node->parent->left = node->left;
node->left->parent = node->parent;
}
free(node);
return (0);
}
else
return (getter_fn(node));
}
/**
 * getter_fn - This function gets the next_of_kin using the minimum
 * value in the right subtree
 * @root: Target
 * Return: The value
*/
int getter_fn(bst_t *root)
{
int x = 0;

x = next_of_kin(root->right);
root->n = x;
return (x);
}
