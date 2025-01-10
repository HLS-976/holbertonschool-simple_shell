#include "main.h"

/**
 * tokenize_line - splits a line into tokens based on delimiters
 *@line: the line to split
 *@delim: the characters delimiting the tokens
 *@token_count: the number of tokens expected
 * Return: an array of pointers to the token, or NULL on error
 */

char **tokenize_line(char *line, const char *delim, int token_count)
{
	char **tokens;
	int i = 0;
	char *token;

	tokens = malloc((token_count + 1) * sizeof(char *));
	if (!tokens)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	i = 0;

	token = strtok(line, delim);

	while (token)
	{
		tokens[i++] = token;
		if (!tokens[i - 1])
		{
			while (--i >= 0)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
