#include "monty.h"

/**
 * is_digit - Checks if a string is a digit
 * @str: The string to check
 *
 * Return: 1 if the string is a digit, otherwise 0
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * is_number - Checks if a string is a number
 * @str: The string to check
 *
 * Return: 1 if the string is a number, otherwise 0
 */
int is_number(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

