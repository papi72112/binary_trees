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

	result = binary_tree_is_root(root);
	printf("Is %d a root: %d\n", root->n, result);
	result = binary_tree_is_root(root->right);
	printf("Is %d a root: %d\n", root->right->n, result);
	result = binary_tree_is_root(root->right->right);
	printf("Is %d a root: %d\n", root->right->right->n, result);
	result = binary_tree_is_root(NULL);
	printf("Is NULL a root: %d\n", result);

	binary_tree_delete(root);
	return (0);
}
