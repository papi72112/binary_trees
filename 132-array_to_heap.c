#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a Max Binary Heap from an array
 * @array: pointer to the first element in the array
 * @size: size of the array
 *
 * Return: pointer to the root of the Max Binary Heap, or NULL on failure
 */
bst_t *array_to_heap(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	while (array != NULL && i < size)
		heap_insert(&tree, array[i++]);

	return (tree);
}
