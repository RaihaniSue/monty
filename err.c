#include "monty.h"

/**
 * report_error - Prints appropriate error messages based on error codes.
 * @error_code: Error codes:
 *   (1) - No file or more than one file provided.
 *   (2) - Unable to open or read the file.
 *   (3) - Invalid instruction in the file.
 *   (4) - Memory allocation failure.
 *   (5) - Non-integer parameter passed to "push" instruction.
 *   (6) - Empty stack error for pint.
 *   (7) - Empty stack error for pop.
 *   (8) - Stack too short for an operation.
 */
void report_error(int error_code, ...)
{
	va_list args;
	char *instruction;
	int line_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * more_error - Handles specific errors.
 * @error_code: Error codes:
 *   (6) - Empty stack error for pint.
 *   (7) - Empty stack error for pop.
 *   (8) - Stack too short for an operation.
 *   (9) - Division by zero.
 */
void more_error(int error_code, ...)
{
	va_list args;
	char *instruction;
	int line_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, instruction);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * string_error - Handles specific string-related errors.
 * @error_code: Error codes:
 *   (10) - Node's number outside ASCII bounds for pchar.
 *   (11) - Empty stack error for pchar.
 */
void string_error(int error_code, ...)
{
	va_list args;
	int line_num;

	va_start(args, error_code);
	line_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}
