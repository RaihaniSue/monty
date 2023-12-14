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
		report_error(2, fileName);

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
	char buffer[BUFSIZ];

	while (fgets(buffer, sizeof(buffer), fileDesc) != NULL)
	{
		format = parseLine(buffer, lineNum, format);
		lineNum++;
	}
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
		report_error(4);

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
