#include "binary_trees.h"

/**
 * enqueue - a function that inserts an element into the queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 * @node: pointer to a node in the binary tree
 *
 * Return: void
 */
void enqueue(queue_t **head, queue_t **tail, const binary_tree_t *node)
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
 * dequeue - a function that removes and returns the head element from a queue
 * @head: double pointer to the head of the queue
 * @tail: double pointer to the tail of the queue
 *
 * Return: pointer to the head (first) element in the queue, otherwise NULL.
 */
queue_t *dequeue(queue_t **head, queue_t **tail)
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
 * binary_tree_levelorder - a function that goees through a binary tree using
 *                          level-order traversal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function that will be applied on the nodes
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head = NULL, *tail = NULL, *queue_element = NULL;

	if (tree != NULL && func != NULL)
	{
		enqueue(&head, &tail, tree);
		while (head != NULL)
		{
			queue_element = dequeue(&head, &tail);
			func(queue_element->tree_node->n);
			enqueue(&head, &tail, queue_element->tree_node->left);
			enqueue(&head, &tail, queue_element->tree_node->right);
			free(queue_element);
		}
	}
}
