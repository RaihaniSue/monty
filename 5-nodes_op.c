#include "monty.h"
/**
 * addStackNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void addStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subStackNodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void subStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lineNumber, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divStackNodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void divStackNodes(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lineNumber, "div");

	if ((*stack)->n == 0)
		more_error(9, lineNumber);

	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
