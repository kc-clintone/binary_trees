#include "binary_trees.h"
/**
 * heap_extract - This function extracts the root node of
 * a Max Binary Heap
 * @root: Pointer to target
 * Return: Sorted value or 0 on failure
*/
int heap_extract(heap_t **root)
{
int x;
heap_t *hr, *nd;

if (!root || !*root)
return (0);
hr = *root;
x = hr->n;
if (!hr->left && !hr->right)
{
*root = NULL;
free(hr);
return (x);
}
fn_8(hr, &nd, th(hr));
hr->n = nd->n;
if (nd->parent->right)
nd->parent->right = NULL;
else
nd->parent->left = NULL;
free(nd);
mkhp(hr);
*root = hr;
return (x);
}
/**
 * fn_8 - Helpwr for pre-order traversal
 * @tr: Pointer to targrt tree
 * @nd: node
 * @ht: Height of tree
 * Return: Nada
*/
void fn_8(heap_t *tr, heap_t **nd, size_t ht)
{
if (!tr)
return;
if (!ht)
*nd = tr;
ht--;
fn_8(tr->left, nd, ht);
fn_8(tr->right, nd, ht);
}
/**
 * mkhp - this function makes a max binary heap
 * @rt: Pointer to target
*/
void mkhp(heap_t *rt)
{
int vl;
heap_t *x, *y;

if (!rt)
return;
x = rt;
while (1)
{
if (!x->left)
break;
if (!x->right)
y = x->left;
else
{
if (x->left->n > x->right->n)
y = x->left;
else
y = y->right;
}
if (x->n > y->n)
break;
vl = x->n;
x->n = y->n;
y->n = vl;
x = y;
}
}
/**
 * tsh - This just measures the sum of heights of a binary tree
 * @tr: Pointer to target
 * Return: Height or 0

size_t tsh(const binary_tree_t *tr)
{
size_t hl = 0, hr = 0;

if (!tr)
return (0);
if (tr->left)
hl = 1 + tsh(tr->left);
if (tr->right)
hr = 1 + tsh(tr->right);
return (hl + hr);
}
*/
/**
 * th - This just measures the height of a binary tree
 * @tree: Pointer to target tree
 * Return: Height or 0
*/
size_t th(const heap_t *tr)
{
size_t hl = 0, hr = 0;

if (!tr)
return (0);
if (tr->left)
hl = 1 + th(tr->left);
if (tr->right)
hr = 1 + th(tr->right);
if (hl > hr)
return (hl);
return (hr);
}
