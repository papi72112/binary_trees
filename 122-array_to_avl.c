#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL Tree from an array
 * @array: pointer to the first element in the array
 * @size: size of the array
 *
 * Return: pointer to the root of the AVL Tree, or NULL if failure occurs
 */
bst_t *array_to_avl(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	while (array != NULL && i < size)
		avl_insert(&tree, array[i++]);

	return (tree);
}
