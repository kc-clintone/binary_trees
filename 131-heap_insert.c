#include "binary_trees.h"
/**
 * heap_insert - This function inserts a value in Max Binary Heap
 * @root: Pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *tr, *new, *tp;
int x, lv, i, j, k, temp;

if (!root)
return (NULL);
if (!(*root))
return (*root = binary_tree_node(NULL, value));
tr = *root;
x = bts(tr);
lv = x;
for (k = 0, i = 1; lv >= i; i *= 2, k++)
lv -= i;
for (j = 1 << (k - 1); j != 1; j >>= 1)
tr = lv & k ? tr->right : tr->left;
new = binary_tree_node(tr, value);
lv & 1 ? (tr->right = new) : (tr->left = new);
tp = new;
for (; tp->parent && (tp->n > tp->parent->n); tp = tp->parent)
{
temp = tp->n;
tp->n = tp->parent->n;
tp->parent->n = temp;
new = new->parent;
}
return (new);
}
/**
 * bts - This measures the size of a binary tree
 * @tr: Target
 * Return: Size or 0 if tree is NULL
*/
size_t bts(const binary_tree_t *tr)
{
if (!tr)
return (0);
return (bts(tr->left) + bts(tr->right) + 1);
}
