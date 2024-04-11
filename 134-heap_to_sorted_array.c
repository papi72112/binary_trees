#include "binary_trees.h"

/**
 * get_size - a function that measures the size of a binary tree.
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree
 */
size_t get_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (get_size(tree->left) + get_size(tree->right) + 1);
}

/**
 * heap_to_sorted_array - a function that converts a Max Binary Heap to sorted
 *                        array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: pointer to the size of the array
 *
 * Return: pointer to the sorted array, or NULL if failure occurs
 * Description: size is assumed to be a valid address to an integer
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i = 0, *sorted_array = NULL;

	if (heap == NULL || size == NULL)
		return (NULL);
	*size = get_size(heap);
	sorted_array = malloc(sizeof(int) * (*size));
	if (sorted_array == NULL)
		return (NULL);
	while (heap != NULL)
		sorted_array[i++] = heap_extract(&heap);
	return (sorted_array);
}
