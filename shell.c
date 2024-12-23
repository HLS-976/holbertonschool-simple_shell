#include "main.h"

/**
 * main - Shell program entry point
 * Return: 0 si le programme s'exécute avec succès, -1 en cas d'erreur
 */

/*Fonction principale*/

int main(void)
{
	const char *prompt = "(shell)-$";
	const char *delim = " \t\n";
	char *lineptr;
	int token_count;
	char *line_copy;
	char **tokens;

	while (1)
	{
		lineptr = read_line(prompt);
		if (!lineptr)
			break;
		token_count = count_tokens(lineptr, delim);

		if (token_count <= 0)
		{
			free(lineptr);
			continue;
		}
		line_copy = strdup(lineptr);

		if (!line_copy)
		{
			perror("Error duplicating line");
			free(lineptr);
			continue;
		}
		tokens = tokenize_line(line_copy, delim, token_count);

		if (!tokens)
		{
			free(lineptr);
			free(line_copy);
			continue;
		}
		/*app la fonction execution*/
		execution(tokens, token_count);

		free(tokens);
		free(line_copy);
		free(lineptr);
	}
	return (0);
}
