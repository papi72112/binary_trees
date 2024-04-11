#include "binary_trees.h"

/**
 * __enqueue - a function that inserts an element into the queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 * @node: pointer to a node in the binary tree
 *
 * Return: void
 */
void __enqueue(queue_t **head, queue_t **tail, const binary_tree_t *node)
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
 * __dequeue - a function that removes and returns the head element from a
 *             queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 *
 * Return: pointer to the head (first) element in the queue, otherwise NULL.
 */
queue_t *__dequeue(queue_t **head, queue_t **tail)
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
 * _swap_values - a function that swaps values of two nodes
 * @a: pointer to the first node
 * @b: pointer to the second node
 *
 * Return: void
 */
void _swap_values(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * get_last_level_order_node - a function that returns the last level-order
 *                             node in a Max Binary Heap
 * @root: pointer to the root node
 *
 * Return: pointer to the last level-order node in a Max Binary Heap
 */
heap_t *get_last_level_order_node(heap_t *root)
{
	queue_t *head = NULL, *tail = NULL, *queue_element = NULL;
	heap_t *last_node = NULL;
	int node_is_last_node = 0;

	if (root == NULL)
		return (NULL);
	__enqueue(&head, &tail, root);
	while (head != NULL)
	{
		queue_element = __dequeue(&head, &tail);
		last_node = (heap_t *)queue_element->tree_node;
		free(queue_element);
		if (node_is_last_node)
			break;
		__enqueue(&head, &tail, last_node->left);
		__enqueue(&head, &tail, last_node->right);
		if (head == tail)
			node_is_last_node = 1;
	}
	return (last_node);
}

/**
 * heap_extract - a function that extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the tree
 *
 * Return: value stored in the root node, or 0 if failure occurs
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *node, *max_node;
	int root_extract;

	if (root == NULL || *root == NULL)
		return (0);
	root_extract = (*root)->n;
	last_node = get_last_level_order_node(*root);
	(*root)->n = last_node->n;
	if (last_node == *root)
		*root = NULL;
	else
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
		/* Now correct the heap */
		node = *root;
		while (node != NULL)
		{
			max_node = node;
			if (node->left && node->left->n > max_node->n)
				max_node = node->left;
			if (node->right && node->right->n > max_node->n)
				max_node = node->right;
			if (max_node == node->left || max_node == node->right)
				_swap_values(&node->n, &max_node->n);
			else
				break;
			node = max_node;
		}
	}
	free(last_node);
	return (root_extract);
}
