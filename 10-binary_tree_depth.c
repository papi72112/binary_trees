#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in a
 *                     binary tree
 * @tree: pointer to the node to be measured
 *
 * Return: void
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *temp = (binary_tree_t *)tree;

	while (temp != NULL && temp->parent != NULL)
	{
		temp = temp->parent;
		++depth;
	}
	return (depth);
}
