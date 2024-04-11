#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that returns the lowest common ancestor
 *                         of two nodes.
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *first_ancestor, *second_ancestor;

	if (first != NULL && second != NULL)
	{
		first_ancestor = (binary_tree_t *)first;
		while (first_ancestor != NULL)
		{
			second_ancestor = (binary_tree_t *)second;
			while (second_ancestor != NULL)
			{
				if (first_ancestor == second_ancestor)
					return (first_ancestor);
				second_ancestor = second_ancestor->parent;
			}
			first_ancestor = first_ancestor->parent;
		}
	}
	return (NULL);
}
