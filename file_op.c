#include "monty.h"

/**
 * openFile - Opens a file
 * @fileName: The file's path
 * Return: void
 */
void openFile(char *fileName)
{
	FILE *fileDescriptor = fopen(fileName, "r");

	if (fileName == NULL || fileDescriptor == NULL)
		err(2, fileName);

	readFile(fileDescriptor);
	fclose(fileDescriptor);
}

/**
 * readFile - Reads a file
 * @fileDesc: Pointer to file descriptor
 * Return: void
 */
void readFile(FILE *fileDesc)
{
	int lineNum = 1;
	int format = 0;
	char *buffer = NULL;
	size_t length = 0;

	while (getline(&buffer, &length, fileDesc) != -1)
	{
		format = parseLine(buffer, lineNum, format);
		lineNum++;
	}
	free(buffer);
}

/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @buff: Line from the file
 * @lineNum: Line number
 * @fmt: Storage format. 0 for stack, 1 for queue.
 * Return: Returns 0 if the opcode is stack, 1 if queue.
 */
int parseLine(char *buff, int lineNum, int fmt)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (fmt);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunction(opcode, val, lineNum, fmt);
	return (fmt);
}

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
		{"push", addToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", noOperation},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotateLeft},
		{"rotr", rotateRight},
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
		err(3, ln, op);
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
			err(5, ln);
		while (val[i] != '\0')
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
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