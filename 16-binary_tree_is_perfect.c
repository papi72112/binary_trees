#include "binary_trees.h"

/**
 * check_internal_nodes - a function that checks if the internal nodes of a
 *                        binary tree have only two children.
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if internal nodes have two children, otherwise 0.
 */
int check_internal_nodes(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (!(tree->left != NULL && tree->right != NULL))
		return (0);
	return (check_internal_nodes(tree->left) &&
			check_internal_nodes(tree->right));
}

/**
 * get_leaf_node_level - a function that return the level of a leaf node in a
 *                       binary tree
 * @tree: pointer to the root node of the binary tree
 * @level: current level in the binary tree recursion
 *
 * Return: level of a leaf node
 * Description: Only the level of a single leaf node is required, so there is
 *              no need to check on both sides of the tree.
 */
int get_leaf_node_level(const binary_tree_t *tree, int level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level);
	return (get_leaf_node_level(tree->left, ++level));
}

/**
 * check_leaf_nodes - a function that checks if the leaf nodes of a binary tree
 *                    are on the same level.
 * @tree: pointer to the root node of the binary tree
 * @level: current level in the binary tree recursion
 * @leaf_level: level of a single leaf node in the binary tree
 *
 * Return: 1 if the leaf nodes are on the same level, otherwise 0.
 */
int check_leaf_nodes(const binary_tree_t *tree, int level, int leaf_level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level == leaf_level);
	++level;
	return (check_leaf_nodes(tree->left, level, leaf_level) &&
			check_leaf_nodes(tree->right, level, leaf_level));
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is a
 *                          perfect binary tree.
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is a perfect binary tree, otherwise 0.
 * Description: a binary tree is said to be perfect when all the internal nodes
 *              have only two children (not 0, 1 or more), and when all the
 *              leaf nodes are on the same level.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level;

	if (tree == NULL)
		return (0);

	leaf_level = get_leaf_node_level(tree, 0);
	return (check_internal_nodes(tree) &&
			check_leaf_nodes(tree, 0, leaf_level));
}
