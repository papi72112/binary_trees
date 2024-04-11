#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that returns the sibling of a node
 * @node: pointer to the node
 *
 * Return: pointer to the sibling node, otherwise NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling_node;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	sibling_node =
		node->parent->left == node ? node->parent->right : node->parent->left;
	return (sibling_node);
}
