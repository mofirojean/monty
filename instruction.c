#include "monty.h"

/**
 * nop -  does nothing
 * @stack: doesnt matter
 * @line_cnt : for nothing
 *
 * Return: NOTHING
 */
void nop(stack_t **stack, unsigned int line_cnt)
{
	(void) stack;
	(void) line_cnt;
}

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt); /*For top node*/
	(*stack)->n = result;
}

/**
 * _sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}


/**
 * _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}

/**
 * _div - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		exit(EXIT_FAILURE);
		;
		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}
