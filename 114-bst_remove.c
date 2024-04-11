#include "binary_trees.h"

/**
 * bst_remove - a function that removes a node from a BST
 * @root: pointer to the root node
 * @value: value of the node to remove in the BST
 *
 * Return: pointer to the new root node of the BST
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL, *inorder_suc = NULL;

	if (root == NULL)
		return (NULL);
	if (value == root->n)
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left == NULL ? root->right : root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			/* Find the inorder successor */
			inorder_suc = root->right;
			while (inorder_suc->left != NULL)
				inorder_suc = inorder_suc->left;
			/**
			 * Connect the parent of the successor and the right child of the
			 * successor, because left child is always NULL.
			 */
			if (inorder_suc->parent->left == inorder_suc)
				inorder_suc->parent->left = inorder_suc->right;
			else
				inorder_suc->parent->right = inorder_suc->right;
			if (inorder_suc->right)
				inorder_suc->right->parent = inorder_suc->parent;
			/* Copy successor data to the root */
			root->n = inorder_suc->n;
			/* Remove the successor */
			free(inorder_suc);
		}
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
		root->right = bst_remove(root->right, value);
	return (root);
}
