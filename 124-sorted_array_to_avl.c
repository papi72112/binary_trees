#include "binary_trees.h"

/**
 * sorted_array_to_avl_rec - a function that builds an AVL tree from a sorted
 *                           array using recursion
 * @array: pointer to the sorted array
 * @parent: parent of the child node
 * @left: left index in the array
 * @right: right index in the array
 *
 * Return: pointer to the root node of the built AVL tree, or NULL on failure
 * Description: it is assumed that the array doesn't contain duplicate values
 */
avl_t *sorted_array_to_avl_rec(int *array, avl_t *parent, int left, int right)
{
	avl_t *child = NULL;
	int mid = (left + right) / 2;

	if (left > right)
		return (NULL);

	child = binary_tree_node(parent, array[mid]);
	if (child == NULL)
		return (NULL);

	child->left = sorted_array_to_avl_rec(array, child, left, mid - 1);
	child->right = sorted_array_to_avl_rec(array, child, mid + 1, right);

	return (child);
}

/**
 * sorted_array_to_avl - a function that builds an AVL tree from a sorted array
 * @array: pointer to the sorted array
 * @size: size of the array
 *
 * Return: pointer to the root node of the built AVL tree, or NULL on failure
 * Description: it is assumed that the array doesn't contain duplicate values
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (sorted_array_to_avl_rec(array, NULL, 0, (int)size - 1));
}
