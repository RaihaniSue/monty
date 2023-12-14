#include "monty.h"
/**
 * findFunction - Finds the appropriate function for the opcode
 * @op: Opcode
 * @value: Argument of the opcode
 * @fmt: Storage format. 0 for stack, 1 for queue.
 * @ln: Line number
 * Return: void
 */
void findFunction(char *op, char *value, int ln, int fmt)
{
	int i = 0;
	int flag = 1;

	instruction_t functions[] = {
		{"push", addNewNode},
		{"pall", printEntireStack},
		{"pint", printTopValue},
		{"pop", removeTopNode},
		{"nop", doNothing},
		{"swap", swapStackNodes},
		{"add", addStackNodes},
		{"sub", subStackNodes},
		{"div", divStackNodes},
		{"mul", multiplyNodes},
		{"mod", moduloNodes},
		{"pchar", printAscii},
		{"pstr", pStr},
		{"rotl", rotaL},
		{"rotr", rotaR},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;

	while (functions[i].opcode != NULL)
	{
		if (strcmp(op, functions[i].opcode) == 0)
		{
			callFunction(functions[i].f, op, value, ln, fmt);
			flag = 0;
			break;
		}
		i++;
	}
	if (flag == 1)
		report_error(3, ln, op);
}

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @fmt: Format specifier. 0 for stack, 1 for queue.
 */
void callFunction(opFunction func, char *op, char *val, int ln, int fmt)
{
	stack_t *node;
	int flag = 1;
	int i = 0;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			report_error(5, ln);
		while (val[i] != '\0')
		{
			if (isdigit(val[i]) == 0)
				report_error(5, ln);
			i++;
		}
		node = createNode(atoi(val) * flag);
		if (fmt == 0)
			func(&node, ln);
		if (fmt == 1)
			addToQueue(&node, ln);
	}
	else
		func(&head, ln);
}
