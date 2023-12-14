#include "monty.h"

/**
 * doNothing - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void doNothing(stack_t **stack, unsigned int lineNumber)
{
	(void) stack;
	(void) lineNumber;
}

/**
 * swapStackNodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void swapStackNodes(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lineNumber, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
