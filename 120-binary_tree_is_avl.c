#include "binary_trees.h"

/**
 * sub_tree_height - a function that measures the height of sub tree of a node
 *                   using recursion
 * @node: pointer to the root node of the tree
 * @level: current level in the tree
 *
 * Return: void
 */
int sub_tree_height(const binary_tree_t *node, size_t level)
{
	int height_left = 0, height_right = 0, height_max = 0;

	if (node == NULL)
		return (-1);
	if (node->left == NULL && node->right == NULL)
		return (level);
	++level;
	height_left = sub_tree_height(node->left, level);
	height_right = sub_tree_height(node->right, level);
	height_max = height_left > height_right ? height_left : height_right;
	return (height_max);
}

/**
 * check_left_tree_bst - a function that checks if the nodes in the left sub
 * tree are smaller than a given value
 * @node_l: pointer to root of the left sub tree
 * @value: value to check with
 *
 * Return: 1 if nodes are smaller than the given value, 0 otherwise
 */
int check_left_tree_bst(const binary_tree_t *node_l, int value)
{
	if (node_l == NULL)
		return (1);
	if (node_l->n >= value)
		return (0);
	return (check_left_tree_bst(node_l->left, value) &&
			check_left_tree_bst(node_l->right, value));
}

/**
 * check_right_tree_bst - a function that checks if the nodes in the right sub
 * tree are greater than a given value
 * @node_r: pointer to root of the right sub tree
 * @value: value to check with
 *
 * Return: 1 if nodes are greater than the given value, 0 otherwise
 */
int check_right_tree_bst(const binary_tree_t *node_r, int value)
{
	if (node_r == NULL)
		return (1);
	if (node_r->n <= value)
		return (0);
	return (check_right_tree_bst(node_r->left, value) &&
			check_right_tree_bst(node_r->right, value));
}

/**
 * binary_tree_is_avl - a function that checks if a binary tree is an AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int cur_bf, is_avl;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	cur_bf = sub_tree_height(tree->left, 0) - sub_tree_height(tree->right, 0);
	if (cur_bf < -1 || cur_bf > 1)
		return (0);

	if (!(check_left_tree_bst(tree->left, tree->n) &&
		  check_right_tree_bst(tree->right, tree->n)))
		return (0);

	if (tree->left != NULL)
		is_avl = binary_tree_is_avl(tree->left);
	if (tree->right != NULL)
		is_avl = is_avl && binary_tree_is_avl(tree->right);

	return (is_avl);
}
