
#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
int n;
struct binary_tree_s *parent;
struct binary_tree_s *left;
struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

/**---others---*/
int pwr_r(int n, int p);
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *);

/*------prototypes-------*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_root(const binary_tree_t *node);
int binary_tree_is_leaf(const binary_tree_t *node);
void binary_tree_delete(binary_tree_t *tree);

/*------advanced---------*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
avl_t *inode(avl_t **t, avl_t *p, avl_t **new, int val);
avl_t *avl_insert(avl_t **tree, int value);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *array_to_bst(int *array, size_t size);
int getter_fn(bst_t *root);
avl_t *array_to_avl(int *array, size_t size);
int clean_up(bst_t *node);
bst_t *brm(bst_t *root, int value);
void balancer(avl_t **t);
int rmt(bst_t *r);
avl_t *sorted_array_to_avl(int *array, size_t size);
int fx(bst_t *n);
avl_t *avl_remove(avl_t *root, int value);
heap_t *heap_insert(heap_t **root, int value);
int next_of_kin(bst_t *node);
size_t binary_tree_height(const binary_tree_t *t);
int binary_tree_is_avl(const binary_tree_t *tree);
int btc(const binary_tree_t *tr);
size_t bts(const binary_tree_t *tr);
int binary_tree_is_heap(const binary_tree_t *tree);
bst_t *bst_remove(bst_t *root, int value);
void fn_1(const binary_tree_t *tree, void (*func)(int), size_t level);
int fn_2(const binary_tree_t *tree, size_t x, size_t s);
int fn_3(const binary_tree_t *tree, int x, int y);
int fn_4(const binary_tree_t *t, int x, int y);
void fn_5(avl_t **r, int *arr, size_t x, size_t y);
int fn_6(const binary_tree_t *tr);
int fn_7(const binary_tree_t *tr, size_t i, size_t x);

#endif /*BINARY_TREES_H*/
