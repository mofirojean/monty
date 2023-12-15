#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define BUILTIN_INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"div", _div},    \
		    {"mul", _mul},    \
		    {"add", _add},    \
		    {"sub", _sub},    \
		    {"nop", nop},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

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

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;

extern help global;

/* stack utility functions available in linked_list.c */
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

/* stack functions for monty manipulation */
void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **stack, unsigned int line_count);
void swap(stack_t **stack, unsigned int line_count);
void pop(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_count);

/* Arithmetic functions for monty manipulation */
void _add(stack_t **stack, unsigned int line_count);
void _sub(stack_t **stack, unsigned int line_count);
void _mul(stack_t **stack, unsigned int line_count);
void _div(stack_t **stack, unsigned int line_count);

/* Executes and runs the builtin operation or opcode */
void run_builtin(stack_t **data_structure, char *instruction,
unsigned int line_number);

/* main function declaration */
void file_error(char *argv);
void error_usage(void);

int is_digit(char *string);
int isnumber(char *str);
#endif
