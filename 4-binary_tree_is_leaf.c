#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: pointer to the node to be checked
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->left == NULL && node->right == NULL);
}
