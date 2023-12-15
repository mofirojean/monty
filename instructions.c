#include "monty.h"

/**
 * push - Adds an element into the stack
 * @stack: The stack provided by main
 * @line_cnt: The line count
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *value = global.argument;

	if (!is_digit(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!create_queue_node(stack, atoi(value)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!prepend_node(stack, atoi(value)))
			exit(EXIT_FAILURE);
	}
}

/**
 * pall - Prints the entire stack
 * @stack: The stack provided by main
 * @line_cnt: The line count (unused)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: The stack provided by main
 * @line_cnt: The line count
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element from the stack
 * @stack: The stack provided by main
 * @line_cnt: The line count
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The stack provided by main
 * @line_cnt: The line count
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *top = NULL;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->n = top->next->n;
	top->next->n = top->n;
}

