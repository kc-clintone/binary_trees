#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value:  Value to store in the new node
 * Description - Parent has left-child? >> new node must take it's place
 * then old left-child now set to left-child of new node.
 * Return: Pointer to the new node, or NULL on failure or if
 * parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;

if (!parent)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->n = value;
new->parent = parent;
new->right = NULL;
new->left = parent->left;
parent->left = new;
if (new->left)
new->left->parent = new;
return (new);
}
