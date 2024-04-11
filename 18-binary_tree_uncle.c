#include "binary_trees.h"

/**
 * binary_tree_uncle - a function that returns the uncle of a node
 * @node: pointer to the node
 *
 * Return: pointer to the uncle node, otherwise NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle_node, *grand_parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	grand_parent = node->parent->parent;
	uncle_node = grand_parent->left == node->parent ? grand_parent->right
													: grand_parent->left;
	return (uncle_node);
}
