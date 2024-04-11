#include "../binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	int array_even[] = {1,	2,	20, 21, 22, 32, 34, 47,
						62, 68, 79, 84, 87, 91, 95, 98};
	int array_odd[] = {1,  2,  20, 21, 22, 32, 34, 47,
					   62, 68, 79, 84, 87, 91, 95};
	size_t n_even = sizeof(array_even) / sizeof(array_even[0]);
	size_t n_odd = sizeof(array_odd) / sizeof(array_odd[0]);

	printf("Even number of nodes ...\n");
	tree = sorted_array_to_avl(array_even, n_even);
	if (!tree)
		return (1);
	print_array(array_even, n_even);
	binary_tree_print(tree);
	binary_tree_delete(tree);

	printf("Odd number of nodes ...\n");
	tree = sorted_array_to_avl(array_odd, n_odd);
	if (!tree)
		return (1);
	print_array(array_odd, n_odd);
	binary_tree_print(tree);
	binary_tree_delete(tree);

	return (0);
}
