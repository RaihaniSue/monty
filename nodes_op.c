#include "monty.h"

/**
 * addNewNode - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */
void addNewNode(stack_t **newNode, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * printEntireStack - Prints the entire stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Line number of the opcode.
 */
void printEntireStack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *current;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * removeTopNode - Removes the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void removeTopNode(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_error(7, lineNumber);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * printTopValue - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printTopValue(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
