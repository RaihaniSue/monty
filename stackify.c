#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument values
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	nodes_free();
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
		report_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * nodes_free - Frees nodes in the stack.
 *
 * Description: Frees all nodes in the stack starting from the provided head.
 */
void nodes_free(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = (head)->next;
		free(tmp);
	}
}

/**
 * addToQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @ln: Line number of the opcode (unused)
 *
 * Description: Adds a new node to the queue starting from the provided head.
 */
void addToQueue(stack_t **newNode, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}
