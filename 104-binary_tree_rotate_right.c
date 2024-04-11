#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that rotates a binary tree to the
 *                            right
 * @tree: pointer to the root node of the binary tree
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	new_root = tree->left;

	/* adjust the old and new root nodes */
	tree->left = new_root->right;
	new_root->right = tree;

	/* adjust the parents of the old and new root nodes */
	new_root->parent = tree->parent;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}
	tree->parent = new_root;

	/* adjust parent of the child node of the old root node */
	if (tree->left)
		tree->left->parent = tree;

	return (new_root);
}
