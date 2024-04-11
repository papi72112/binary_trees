#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int result;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	result = binary_tree_is_leaf(NULL);
	printf("Is NULL a leaf: %d\n", result);
	result = binary_tree_is_leaf(root);
	printf("Is %d a leaf: %d\n", root->n, result);
	result = binary_tree_is_leaf(root->right);
	printf("Is %d a leaf: %d\n", root->right->n, result);
	result = binary_tree_is_leaf(root->right->right);
	printf("Is %d a leaf: %d\n", root->right->right->n, result);
	binary_tree_delete(root);
	return (0);
}
