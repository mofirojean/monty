#include "monty.h"

/**
 * run_builtin - Executes built-in operations
 * @data_structure: Pointer to the stack or queue structure
 * @instruction: Instruction to execute
 * @line_number: Current line number in the script
 *
 * This function executes the specified built-in operation based on
 * the instruction provided, managing either a stack or
 * queue based on the data_structure.
 */
void run_builtin(stack_t **data_structure, char *instruction,
unsigned int line_number)
{
	int index = 0;

	instruction_t operations[] = BUILTIN_INSTRUCTIONS;

	if (!strcmp(instruction, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(instruction, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (operations[index].opcode)
	{
		if (strcmp(operations[index].opcode, instruction) == 0)
		{
			operations[index].f(data_structure, line_number);
			return; /* Execute the matched function */
		}
		index++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}

