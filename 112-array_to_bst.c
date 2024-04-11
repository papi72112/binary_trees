#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: pointer to the first element in the array
 * @size: size of the array
 *
 * Return: pointer to the root of the created BST, or NULL if failure occurs
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	while (array != NULL && i < size)
		bst_insert(&tree, array[i++]);

	return (tree);
}
