#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the left-child of
 *                           another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: if successful pointer to the new node, otherwise NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;

	/* Make the new node the left child of parent */
	temp = parent->left;
	if (temp != NULL)
		temp->parent = new_node;
	parent->left = new_node;
	new_node->left = temp;

	return (new_node);
}
