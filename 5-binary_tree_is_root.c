#include "binary_trees.h"

/**
 * binary_tree_is_root - a function that checks if a node is a root
 * @node: pointer to the node to be checked
 *
 * Return: 1 if the node is a root, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
