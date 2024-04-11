#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: pointer to the parent of the new node
 * @value: value to put in the new node
 *
 * Return: if successful, pointer to the new node, otherwise NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = new_node->right = NULL;
	return (new_node);
}
