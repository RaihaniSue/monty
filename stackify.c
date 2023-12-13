#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument values
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1], &head);
	freeNodes(&head);
	return (0);
}

/**
 * createNode - Creates a node.
 * @n: Number to be stored in the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees nodes in the stack.
 * @head: Pointer to the top node of the stack.
 *
 * Description: Frees all nodes in the stack starting from the provided head.
 */
void freeNodes(stack_t **head)
{
	stack_t *tmp;

	if (*head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a node to the queue.
 * @head: Pointer to the top node of the stack.
 * @newNode: Pointer to the new node.
 * @ln: Line number of the opcode (unused)
 *
 * Description: Adds a new node to the queue starting from the provided head.
 */
void addToQueue(stack_t **head, stack_t **newNode,
		__attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (*head == NULL)
	{
		*head = *newNode;
		return;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}
