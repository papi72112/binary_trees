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
 * binary_tree_balance - a function that measures the balance factor of a
 *                       binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (sub_tree_height(tree->left, 0) - sub_tree_height(tree->right, 0));
}
