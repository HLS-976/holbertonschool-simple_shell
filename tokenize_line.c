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

	tokens = malloc((token_count + 1) * sizeof(char *)); /* Allocates a dynamicly memory */
	if (!tokens)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	i = 0;

	token = strtok(line, delim); /* Divide the line input according to the delimiter */

	while (token)
	{
		tokens[i++] = token;
		if (!tokens[i - 1]) /* Checks if the last tokens is null */
		{
			while (--i >= 0) /* frees each token */
				free(tokens[i]);
			free(tokens); /* frees the tokens array */
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
