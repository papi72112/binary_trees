#include "binary_trees.h"

/**
 * check_left_tree - a function that checks if the nodes in the left sub tree
 *                   are smaller than a given value
 * @node_l: pointer to root of the left sub tree
 * @value: value to check with
 *
 * Return: 1 if nodes are smaller than the given value, 0 otherwise
 */
int check_left_tree(const binary_tree_t *node_l, int value)
{
	if (node_l == NULL)
		return (1);
	if (node_l->n >= value)
		return (0);
	return (check_left_tree(node_l->left, value) &&
			check_left_tree(node_l->right, value));
}

/**
 * check_right_tree - a function that checks if the nodes in the right sub tree
 *                    are greater than a given value
 * @node_r: pointer to root of the right sub tree
 * @value: value to check with
 *
 * Return: 1 if nodes are greater than the given value, 0 otherwise
 */
int check_right_tree(const binary_tree_t *node_r, int value)
{
	if (node_r == NULL)
		return (1);
	if (node_r->n <= value)
		return (0);
	return (check_right_tree(node_r->left, value) &&
			check_right_tree(node_r->right, value));
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a BST
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is a BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (!(check_left_tree(tree->left, tree->n) &&
		  check_right_tree(tree->right, tree->n)))
		return (0);
	if (tree->left != NULL)
		is_bst = binary_tree_is_bst(tree->left);
	if (tree->right != NULL)
		is_bst = is_bst && binary_tree_is_bst(tree->right);
	return (is_bst);
}
