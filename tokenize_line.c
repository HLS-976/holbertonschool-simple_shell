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
	char *token;

	if (!tokens)
	{
		perror("Error allocating memory for tokens");
		return (NULL);
	}

	token = strtok(line, delim);

	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
