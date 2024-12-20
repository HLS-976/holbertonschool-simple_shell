#include "main.h"

/**
 * count_tokens - Counts the number of tokens in a line
 * @line: The line to split into tokens
 * @delim: The characters delimiting the tokens
 * Return: The number of tokens found, or -1 on error
 */


/* Fonction pour compter le nombre de tokens dans une ligne*/

int count_tokens(const char *line, const char *delim)
{
	int count = 0;
	char *line_copy = strdup(line);

	if (!line_copy)
	{
		perror("Error duplicating line");
		return (-1);
	}

	char *token = strtok(line_copy, delim);

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(line_copy);
	return (count);
}
