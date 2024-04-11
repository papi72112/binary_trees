#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	avl_t *root;
	avl_t *node;
	int array[] = {704, 309, 995, 739, 526, 294, 783, 645, 11,	775,
				   689, 452, 390, 770, 189, 369, 300, 721, 891, 6,
				   225, 298, 846, 549, 118, 278, 124, 867, 217, 468,
				   804, 543, 876, 65,  179, 2,	 382, 568, 321, 768,
				   56,	422, 586, 574, 533, 148, 707, 701, 715, 735};
	size_t size = sizeof(array) / sizeof(array[0]);
	size_t i;

	root = NULL;
	for (i = 0; i < size; i++)
	{
		node = avl_insert(&root, array[i]);
		binary_tree_print(root);
		if (node)
			printf("Value inserted: %d\n", node->n);
		else
		{
			printf("Value not inserted: %d\n", array[i]);
		}
		printf("\n");
	}

	binary_tree_delete(root);
	return (0);
}
