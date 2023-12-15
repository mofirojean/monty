#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Ignored.
 * @line_count: Line count (not used).
 *
 * Return: Void.
 */
void nop(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}

/**
 * _add - Adds the top two elements of the stack.
 * @stack: The stack.
 * @line_count: Line count.
 *
 * Return: Void.
 */
void _add(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = result;
}

/**
 * _sub - Subtracts the top two elements of the stack.
 * @stack: The stack.
 * @line_count: Line count.
 *
 * Return: Void.
 */
void _sub(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = result;
}

/**
 * _mul - Multiplies the top two elements of the stack.
 * @stack: The stack.
 * @line_count: Line count.
 *
 * Return: Void.
 */
void _mul(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = result;
}

/**
 * _div - Divides the top two elements of the stack.
 * @stack: The stack.
 * @line_count: Line count.
 *
 * Return: Void.
 */
void _div(stack_t **stack, unsigned int line_count)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = result;
}

