#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a node into a BST
 * @tree: double pointer to the root node of the BST
 * @value: value of the new node
 *
 * Return: pointer to the new node, or NULL if failure or duplication occurs
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *ptr = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);
	ptr = *tree;
	while (ptr != NULL)
	{
		parent = ptr;
		if (value == ptr->n)
			return (NULL);
		else if (value < ptr->n)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (parent == NULL)
		*tree = new_node = binary_tree_node(NULL, value);
	else if (value < parent->n)
		parent->left = new_node = binary_tree_node(parent, value);
	else
		parent->right = new_node = binary_tree_node(parent, value);

	return (new_node);
}
