#include "binary_trees.h"
/**
 * print_tree - This stores recursively each level in an array of strings
 * @tree: Pointer to target node
 * @offset: Offset
 * @depth: Depth
 * @chr: Buffer
 * Return: Length
*/
static int print_tree(const binary_tree_t *tree, int offset, int depth,
char **chr)
{
char bfr[6];
int w, x, y, l, j;

if (!tree)
return (0);
l = (tree->parent && tree->parent->left == tree);
w = sprintf(bfr, "(%03d)", tree->n);
x = print_t(tree->left, offset, depth + 1, chr);
y = print_t(tree->right, offset + x + w, depth + 1, chr);
for (j = 0; j < w; j++)
chr[depth][offset + x + j] = bfr[j];
if (depth && l)
{
for (j = 0; j < w + y; j++)
chr[depth - 1][offset + x + w / 2 + j] = '-';
chr[depth - 1][offset + x + w / 2] = '.';
}
else if (depth && !l)
{
for (j = 0; j < x + w; j++)
chr[depth - 1][offset - w / 2 + j] = '-';
chr[depth - 1][offset + x + w / 2] = '.';
}
return (x + w + y);
}
