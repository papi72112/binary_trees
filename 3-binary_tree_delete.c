#include "binary_trees.h"

/**
 * binary_tree_delete - a function that deletes an entire binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Delete the left side */
	binary_tree_delete(tree->left);
	free(tree->left);

	/* Delete the right side */
	binary_tree_delete(tree->right);
	free(tree->right);

	/* Delete the root node */
	if (tree->parent == NULL)
		free(tree);
}
