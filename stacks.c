#include "monty.h"

/**
 * create_queue_node - Creates and adds a node to the end of a stack_t stack.
 * @stack: The head of the stack
 * @value: The value to be assigned to the new node
 *
 * This function creates a new node with the given value and appends it to the
 * end of the stack. If memory allocation fails, it returns NULL.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *create_queue_node(stack_t **stack, const int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current;

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->next = NULL;

	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	current = *stack;

	while (current->next)
		current = current->next;

	new_node->prev = current;
	current->next = new_node;

	return (new_node);
}

/**
 * prepend_node - Adds a node to the beginning of a stack_t stack.
 * @stack: The head of the stack
 * @value: The value for the new node
 *
 * This function creates a new node with the provided value and adds it to the
 * start of the stack. It returns a pointer to the newly created node or NULL
 * on failure.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *prepend_node(stack_t **stack, const int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * print_stack - Prints the elements of a stack_t stack.
 * @stack: The head of the stack
 *
 * This function prints the contents of the stack and returns the number of
 * elements present in the stack.
 *
 * Return: The number of elements in the stack.
 */
size_t print_stack(const stack_t *stack)
{
	size_t count = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		count++;
	}

	return (count);
}

/**
 * free_stack - Frees a stack_t linked list.
 * @stack: The head of the stack
 *
 * This function frees the memory allocated for a stack_t linked list.
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;

		free(temp);
	}
}

