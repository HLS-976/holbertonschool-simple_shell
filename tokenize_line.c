#include "main.h"

/**
 * tokenize_line - splits a line into tokens based on delimiters
 *@line: the line to split
 *@delim: the characters delimiting the tokens
 *@token_count: the number of tokens expected
 * Return: an array of pointers to the token, or NULL on error
 */


/* Fonction pour extraire les tokens et les stocker dans un tableau dynamique*/

char **tokenize_line(char *line, const char *delim, int token_count)
{
	char **tokens = malloc((token_count + 1) * sizeof(char *));
	int i = 0;
	char *token; *saveptr;

	if (!tokens)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	token = strtok(line, delim, &saveptr);

	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("Error duplicating token");
			while (i > 0)
				free(tokens[--i]);
			free(tokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim, &saveptr);
	}
	tokens[i] = NULL;

	return (tokens);
}
