#include "binary_trees.h"

/**
 * _bst_remove - a function that removes a node from a BST
 * @root: pointer to the root node
 * @value: value of the node to remove in the BST
 *
 * Return: pointer to the new root node of the BST
 */
bst_t *_bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL, *inorder_suc = NULL;

	if (value == root->n)
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left == NULL ? root->right : root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else
		{
			/* Find the inorder successor */
			inorder_suc = root->right;
			while (inorder_suc->left != NULL)
				inorder_suc = inorder_suc->left;
			/**
			 * Connect the parent of the successor and the right child of the
			 * successor, because left child is always NULL.
			 */
			if (inorder_suc->parent->left == inorder_suc)
				inorder_suc->parent->left = inorder_suc->right;
			else
				inorder_suc->parent->right = inorder_suc->right;
			if (inorder_suc->right)
				inorder_suc->right->parent = inorder_suc->parent;
			/* Copy successor data to the root */
			root->n = inorder_suc->n;
			/* Remove the successor */
			free(inorder_suc);
		}
	else if (value < root->n)
		root->left = _bst_remove(root->left, value);
	else
		root->right = _bst_remove(root->right, value);
	return (root);
}

/**
 * _height - a function that measures the height of sub tree of a node
 *           using recursion
 * @node: pointer to the root node of the tree
 * @level: current level in the tree
 *
 * Return: void
 */
int __height(const binary_tree_t *node, size_t level)
{
	int height_left = 0, height_right = 0, height_max = 0;

	if (node == NULL)
		return (-1);
	if (node->left == NULL && node->right == NULL)
		return (level);
	++level;
	height_left = __height(node->left, level);
	height_right = __height(node->right, level);
	height_max = height_left > height_right ? height_left : height_right;
	return (height_max);
}

/**
 * _get_avl_imbalance_node - a function that returns the imbalanced node from
 *                          an AVL tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to an imbalanced node, or NULL if the AVL tree is balanced
 */
avl_t *_get_avl_imbalance_node(const binary_tree_t *tree)
{
	int cur_bf;
	avl_t *imbalanced_node = NULL;

	if (tree->left != NULL)
		imbalanced_node = _get_avl_imbalance_node(tree->left);
	if (tree->right != NULL && imbalanced_node == NULL)
		imbalanced_node = _get_avl_imbalance_node(tree->right);

	if (!imbalanced_node)
	{
		cur_bf = binary_tree_balance(tree);
		if (cur_bf < -1 || cur_bf > 1)
			return ((avl_t *)tree);
	}

	return (imbalanced_node);
}

/**
 * _get_insertion_direction - a function that determines the insertion
 *                            direction of that a new inserted node took
 * @tree: pointer to the root node of the AVL tree
 *
 * Return: insertion direction of the new node
 */
int _get_insertion_direction(const binary_tree_t *tree)
{
	int ins_dir = -1;

	if (binary_tree_balance(tree) > 1)
	{
		if (binary_tree_balance(tree) >= 0)
			ins_dir = LL;
		else
			ins_dir = LR;
	}
	else
	{
		if (binary_tree_balance(tree) >= 0)
			ins_dir = RL;
		else
			ins_dir = RR;
	}

	return (ins_dir);
}

/**
 * avl_remove - a function that removes a node from an AVL tree
 * @root: pointer to the root node
 * @value: value of the node to remove in the AVL tree
 *
 * Return: pointer to the new root node of the AVL tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *imbalanced_node = NULL;
	int ins_dir;

	if (root == NULL)
		return (NULL);
	root = _bst_remove(root, value);
	imbalanced_node = _get_avl_imbalance_node(root);
	if (imbalanced_node)
	{
		ins_dir = _get_insertion_direction(imbalanced_node);
		if (LEFT(ins_dir))
		{
			if (ins_dir == LR)
				imbalanced_node->left =
					binary_tree_rotate_left(imbalanced_node->left);
			if (imbalanced_node == root)
				root = binary_tree_rotate_right(imbalanced_node);
			else
				binary_tree_rotate_right(imbalanced_node);
		}
		else
		{
			if (ins_dir == RL)
				imbalanced_node->right =
					binary_tree_rotate_right(imbalanced_node->right);
			if (imbalanced_node == root)
				root = binary_tree_rotate_left(imbalanced_node);
			else
				binary_tree_rotate_left(imbalanced_node);
		}
	}
	return (root);
}
