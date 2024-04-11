#include "binary_trees.h"

/**
 * swap_nodes - a function that swaps the values of two nodes
 * @n1: pointer to the first node
 * @n2: pointer to the second node
 *
 * Return: void
 */
void swap_nodes(bst_t *n1, bst_t *n2)
{
	int temp;

	if (n1 != NULL && n2 != NULL)
	{
		temp = n1->n;
		n1->n = n2->n;
		n2->n = temp;
	}
}

/**
 * delete_bst_node - a function that deletes a node from BST recursively
 * @root: pointer to the root node
 * @value: value of the node to remove in the BST
 *
 * Return: void
 */
void delete_bst_node(bst_t *root, int value)
{
	bst_t *inorder_suc = NULL;

	if (root == NULL)
		return;
	if (root->n == value)
		if (root->left == NULL && root->right == NULL)
		{
			if (root->parent->left == root)
				root->parent->left = NULL;
			else
				root->parent->right = NULL;
			free(root);
			return;
		}
		else if (root->right == NULL)
		{
			swap_nodes(root, root->left);
			delete_bst_node(root->left, value);
		}
		else
		{
			inorder_suc = root->right;
			while (inorder_suc->left != NULL)
				inorder_suc = inorder_suc->left;
			swap_nodes(root, inorder_suc);
			delete_bst_node(root->right, value);
		}
	else if (value < root->n)
		delete_bst_node(root->left, value);
	else
		delete_bst_node(root->right, value);
}

/**
 * bst_remove - a function that removes a node from a BST
 * @root: pointer to the root node
 * @value: value of the node to remove in the BST
 *
 * Return: pointer to the new root node of the BST
 */
bst_t *bst_remove(bst_t *root, int value)
{
	delete_bst_node(root, value);
	return (root);
}
