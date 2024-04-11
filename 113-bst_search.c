#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a BST
 * @tree: pointer to the root node of the BST tree
 * @value: value to search for in the BST
 *
 * Return: pointer to the node if found, otherwise NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	while (node != NULL)
		if (value == node->n)
			return (node);
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;

	return (NULL);
}
