/*
 * Define _POSIX_C_SOURCE to enable specific POSIX
 * features or ensure compatibility with a particular
 * version of the POSIX standard (e.g., POSIX 2008).
 */
#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/* global var declaration */
int status = 0;
help global;

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		print_usage_error();

	run_monty_program(argc, argv);
	return (EXIT_SUCCESS);
}

/**
 * run_monty_program - Evaluates and executes the monty code.
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: Void.
 */
void run_monty_program(int argc, char **argv)
{
	FILE *file;
	size_t line_length = 0;
	char *line = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.data_struct = 1; /** Defined in monty.h */
	file = fopen(argv[1], "r");

	if (argc != 2)
		print_usage_error();
	if (!file)
		print_file_error(argv[1]);
	while (getline(&line, &line_length, file) != -1)
	{
		if (*line == '\n')
		{
			line_cnt++;
			continue;
		}

		opcode = strtok(line, " \t\n");

		if (!opcode || *opcode == '#')
		{
			line_cnt++;
			continue;
		}

		global.argument = strtok(NULL, " \t\n");
		run_builtin(&stack, opcode, line_cnt);
		line_cnt++;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * print_file_error - prints file error message and exits
 * @filename: filename of the respecive file.
 *
 * Desc: print msg if  not possible to open the file
 * Return: nothing
 */
void print_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * print_usage_error - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

