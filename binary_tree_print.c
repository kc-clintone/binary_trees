#include "binary_trees.h"
/**
 * binary_tree_print - This function prints a binary tree
 * @tree: Pointer to the root of target tree
*/
void binary_tree_print(const binary_tree_t *tree)
{
char **chr;
size_t x, y, z;

if (!tree)
return;
z = get_height(tree);
chr = malloc(sizeof(*chr) * (z + 1));
if (!chr)
return;
for (x = 0; x < z + 1; x++)
{
chr[x] = malloc(sizeof(**chr) * 255);
if (!chr[x])
return;
memset(chr[x], 32, 255);
}
print_tree(tree, 0, 0, x);
for (x = 0; x < z + 1; x++)
{
for (y = 254; y > 1; --y)
{
if (chr[x][y] != ' ')
break;
chr[x][y] = '\0';
}
printf("%s\n", chr[x]);
free(chr[x]);
}
free(chr);
}
/**
 * get_height - This function measures the height of a binary tree
 * @tree: Pointer to target node
 * Return: The height of the tree
*/
static size_t get_height(const binary_tree_t *tree)
{
size_t xl, xr;

xl = tree->left ? 1 + _height(tree->left) : 0;
xr = tree->right ? 1 + _height(tree->right) : 0;
return (xl > xr ? xl : xr);
}
