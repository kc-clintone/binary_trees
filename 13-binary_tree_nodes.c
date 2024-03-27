#include "binary_trees.h"
/**
 * binary_tree_nodes - This function counts the nodes with at least
 * 1 child in a binary tree
 * @tree: Target tree
 * Return: Nodes | 0 if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
if (!tree || (!tree->left && !tree->right))
return (0);
return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
/**
 * binary_tree_leaves - This function counts the leaves in a binary tree
 * @tree: Target tree
 * Return: Leaves | 0 if tree is NULL
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
if (!tree)
return (0);
if (!tree->left && !tree->right)
return (1);
return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
/**
 * binary_tree_size - This function measures the size of a binary tree
 * @tree: Target tree
 * Return: Target tree | 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
