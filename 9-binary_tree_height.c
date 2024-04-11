#include "binary_trees.h"

/**
 * get_height - a function that measures the height of a binary tree using
 *              recursion
 * @tree: pointer to the root node of the tree
 * @level: current level in the tree
 *
 * Return: void
 */
size_t get_height(const binary_tree_t *tree, size_t level)
{
	size_t height_left = 0, height_right = 0, height_max = 0;

	if (tree == NULL)
		return (level);
	++level;
	height_left = get_height(tree->left, level);
	height_right = get_height(tree->right, level);
	height_max = height_left > height_right ? height_left : height_right;
	return (height_max);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: void
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t level = -1;

	return (get_height(tree, level));
}
