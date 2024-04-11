#include "binary_trees.h"

/**
 * _bst_insert - a function that inserts a node into a BST
 * @tree: double pointer to the root node of the BST
 * @value: value of the new node
 *
 * Return: pointer to the new node, or NULL if failure or duplication occurs
 */
bst_t *_bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *ptr = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);
	ptr = *tree;
	while (ptr != NULL)
	{
		parent = ptr;
		if (value == ptr->n)
			return (NULL);
		else if (value < ptr->n)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (parent == NULL)
		*tree = new_node = binary_tree_node(NULL, value);
	else if (value < parent->n)
		parent->left = new_node = binary_tree_node(parent, value);
	else
		parent->right = new_node = binary_tree_node(parent, value);

	return (new_node);
}

/**
 * get_avl_imbalance_node - a function that returns the imbalanced node from
 *                          an AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to an imbalanced node, or NULL if the AVL tree is balanced
 */
avl_t *get_avl_imbalance_node(const binary_tree_t *tree)
{
	int cur_bf;
	avl_t *imbalanced_node = NULL;

	if (tree->left != NULL)
		imbalanced_node = get_avl_imbalance_node(tree->left);
	if (tree->right != NULL && imbalanced_node == NULL)
		imbalanced_node = get_avl_imbalance_node(tree->right);

	if (!imbalanced_node)
	{
		cur_bf = binary_tree_balance(tree);
		if (cur_bf < -1 || cur_bf > 1)
			return ((avl_t *)tree);
	}

	return (imbalanced_node);
}

/**
 * get_insertion_direction - a function that determines the insertion direction
 *                           of that a new inserted node took
 * @tree: pointer to the root node of the AVL tree
 *
 * Return: insertion direction of the new node
 */
int get_insertion_direction(const binary_tree_t *tree)
{
	int ins_dir = -1;

	if (binary_tree_balance(tree) >= 1)
	{
		if (binary_tree_balance(tree->left) >= 0)
			ins_dir = LL;
		else
			ins_dir = LR;
	}
	else
	{
		if (binary_tree_balance(tree->right) >= 0)
			ins_dir = RL;
		else
			ins_dir = RR;
	}

	return (ins_dir);
}

/**
 * avl_insert - a function that inserts a value in an AVL tree
 * @tree: double pointer to the root node of the BST
 * @value: value of the new node
 *
 * Return: pointer to the new node, or NULL if failure or duplication occurs
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = _bst_insert(tree, value), *imbalanced_node = NULL;
	int ins_dir;

	if (new_node == NULL)
		return (NULL);

	imbalanced_node = get_avl_imbalance_node(*tree);
	if (imbalanced_node)
	{
		ins_dir = get_insertion_direction(imbalanced_node);
		if (LEFT(ins_dir))
		{
			if (ins_dir == LR)
				imbalanced_node->left =
					binary_tree_rotate_left(imbalanced_node->left);
			if (imbalanced_node == *tree)
				*tree = binary_tree_rotate_right(imbalanced_node);
			else
				binary_tree_rotate_right(imbalanced_node);
		}
		else
		{
			if (ins_dir == RL)
				imbalanced_node->right =
					binary_tree_rotate_right(imbalanced_node->right);
			if (imbalanced_node == *tree)
				*tree = binary_tree_rotate_left(imbalanced_node);
			else
				binary_tree_rotate_left(imbalanced_node);
		}
	}
	return (new_node);
}
