#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is a full
 *                       binary tree
 * @tree: pointer to the root node
 *
 * Return: 1 if the binary tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Stop recursion when your get to a leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}
