#include "main.h"

/**
 *child_exit - checks if the command is "exit"
 *@tokens: array of tokens
 *@line_copy: copy of the command line
 *@lineptr: pointer to the original command line
 *Return: 0 if the command is "exit", 1 otherwise
 */

int child_exit(char **tokens, char *line_copy, char *lineptr)
{
	if (strcmp(tokens[0], "exit") == 0)
	{
		free(tokens);
		free(line_copy);
		free(lineptr);
		return (0);
	}
	return (1);
}
