#include "binary_trees.h"

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
 * get_insertion_node - a function that returns the correct node in the Max
 *                      Binary Heap tree for insertion
 * @root: pointer to the root of the tree
 *
 * Return: pointer to the correct node for insertion
 * Description: the appropriate place for insertion in a Binary heap is at a
 *              node which is
 *                - NULL = suggesting an empty tree
 *                - a leaf node
 *                - a node with no children that comes right after a full node
 */
heap_t *get_insertion_node(heap_t *root)
{
	queue_t *head = NULL, *tail = NULL, *queue_element = NULL;
	const binary_tree_t *node;
	heap_t *ins_node = NULL;

	if (root == NULL)
		return (NULL);
	_enqueue(&head, &tail, root);
	while (head != NULL)
	{
		queue_element = _dequeue(&head, &tail);
		node = queue_element->tree_node;
		free(queue_element);
		if ((node->left == NULL && node->right == NULL) ||
			!(node->left != NULL && node->right != NULL))
		{
			ins_node = (heap_t *)node;
			break;
		}
		_enqueue(&head, &tail, node->left);
		_enqueue(&head, &tail, node->right);
	}
	free_queue(&head, &tail);
	return (ins_node);
}

/**
 * swap_values - a function that swaps values of two nodes
 * @a: pointer to the first node
 * @b: pointer to the second node
 *
 * Return: void
 */
void swap_values(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heap_insert - a function that inserts a value in to a Max Binary Heap
 * @root: double pointer to the root node of the tree
 * @value: value of the new node
 *
 * Return: pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *ins_node;

	if (root == NULL)
		return (NULL);

	ins_node = get_insertion_node(*root);
	if (ins_node == NULL)
		*root = new_node = binary_tree_node(NULL, value);
	else if (ins_node->left == NULL)
		ins_node->left = new_node = binary_tree_node(ins_node, value);
	else
		ins_node->right = new_node = binary_tree_node(ins_node, value);
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap_values(&new_node->n, &new_node->parent->n);
		new_node = new_node->parent;
	}
	return (new_node);
}
