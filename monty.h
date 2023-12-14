#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*opFunction)(stack_t **, unsigned int);
void doNothing(stack_t **stack, unsigned int lineNumber);
void swapStackNodes(stack_t **stack, unsigned int lineNumber);
void addStackNodes(stack_t **stack, unsigned int lineNumber);
void subStackNodes(stack_t **stack, unsigned int lineNumber);
void divStackNodes(stack_t **stack, unsigned int lineNumber);
void multiplyNodes(stack_t **stack, unsigned int lineNumber);
void moduloNodes(stack_t **stack, unsigned int lineNumber);
void printAscii(stack_t **stack, unsigned int lineNumber);
void pStr(stack_t **stack, __attribute__((unused))unsigned int lineNumber);
void rotaL(stack_t **stack, __attribute__((unused))unsigned int lineNumber);
void rotaR(stack_t **stack, __attribute__((unused))unsigned int lineNumber);
void report_error(int error_code, ...);
void more_error(int error_code, ...);
void string_error(int error_code, ...);
void openFile(char *fileName);
void readFile(FILE *fileDesc);
int parseLine(char *buff, int lineNum, int fmt);
void findFunction(char *op, char *value, int ln, int fmt);
void callFunction(opFunction func, char *op, char *val, int ln, int fmt);
void addNewNode(stack_t **newNode, __attribute__((unused)) unsigned int ln);
void printEntireStack(stack_t **stack, unsigned int lineNumber);
void removeTopNode(stack_t **stack, unsigned int lineNumber);
void printTopValue(stack_t **stack, unsigned int lineNumber);
int main(int argc, char *argv[]);
stack_t *createNode(int n);
void nodes_free(void);
void addToQueue(stack_t **newNode, __attribute__((unused)) unsigned int ln);
#endif
