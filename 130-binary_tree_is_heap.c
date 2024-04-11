#include "binary_trees.h"

#define IS_MAX_HEAP                                               \
	((node->left ? check_descendants(node->left, node->n) : 1) && \
	 (node->right ? check_descendants(node->right, node->n) : 1))

/**
 * _enqueue - a function that inserts an element into the queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 * @node: pointer to a node in the binary tree
 *
 * Return: void
 */
void _enqueue(queue_t **head, queue_t **tail, const binary_tree_t *node)
{
	queue_t *new_queue_element;

	if (node != NULL)
	{
		new_queue_element = malloc(sizeof(queue_t));
		if (new_queue_element == NULL)
			return;
		new_queue_element->tree_node = node;
		new_queue_element->next = NULL;
		if (*tail == NULL)
			*head = *tail = new_queue_element;
		else
			*tail = (*tail)->next = new_queue_element;
	}
}

/**
 * _dequeue - a function that removes and returns the head element from a queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 *
 * Return: pointer to the head (first) element in the queue, otherwise NULL.
 */
queue_t *_dequeue(queue_t **head, queue_t **tail)
{
	queue_t *head_element = NULL;

	if (*head != NULL)
	{
		head_element = *head;
		if (*head == *tail)
			*head = *tail = NULL;
		else
			*head = (*head)->next;
	}

	return (head_element);
}

/**
 * free_queue - a function that frees the queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 *
 * Return: void
 */
void free_queue(queue_t **head, queue_t **tail)
{
	queue_t *temp;

	while (*head != NULL)
	{
		temp = _dequeue(head, tail);
		free(temp);
	}
}

/**
 * check_descendants - a function that checks if the descendants of a tree are
 *                     smaller than a given value
 * @tree: pointer to the root node of the tree
 * @value: given value
 *
 * Return: 1 if all descendants are smaller, otherwise 0
 */
int check_descendants(const binary_tree_t *tree, int value)
{
	int result;

	if (tree->left == NULL && tree->right == NULL)
	{
		if (value > tree->n)
			return (1);
		return (0);
	}

	result = value > tree->n;
	if (tree->left)
		result = result && check_descendants(tree->left, value);
	if (tree->right)
		result = result && check_descendants(tree->right, value);

	return (result);
}

/**
 * binary_tree_is_heap - a function that checks if a binary tree is a valid
 *                       Max-binary heap
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is a Max-binary heap, otherwise 0.
 * Description: This function uses the idea of a full node to check if a binary
 *              tree is a complete binary tree. A full node is a node which has
 *              both left and right child. A complete binary tree is a binary
 *              tree where if a node is not full, then it must have the left
 *              child, and all nodes after the non-full node must also be
 *              non-full nodes.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	queue_t *head = NULL, *tail = NULL, *queue_element;
	const binary_tree_t *node;
	int prev_node_is_full = 1, not_complete = 0;

	if (tree == NULL)
		return (0);
	_enqueue(&head, &tail, tree);
	while (head != NULL)
	{
		queue_element = _dequeue(&head, &tail);
		node = queue_element->tree_node;
		free(queue_element);
		if (!IS_MAX_HEAP)
		{
			not_complete = 1;
			break;
		}
		if (node->left != NULL)
			if (!prev_node_is_full)
			{
				not_complete = 1;
				break;
			}
		prev_node_is_full = node->left == NULL ? 0 : prev_node_is_full;
		if (node->right != NULL)
			if (!prev_node_is_full)
			{
				not_complete = 1;
				break;
			}
		prev_node_is_full = node->right == NULL ? 0 : prev_node_is_full;
		_enqueue(&head, &tail, node->left);
		_enqueue(&head, &tail, node->right);
	}
	free_queue(&head, &tail);
	if (not_complete)
		return (0);
	return (1);
}
