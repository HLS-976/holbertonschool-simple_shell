#include "main.h"
/**
 * main - Shell program entry point
 * Return: 0 si le programme s'exécute avec succès, -1 en cas d'erreur
 */
int main(void)
{
	const char *prompt = "(shell)-$ ";
	const char *delim = " \t\n";
	char *lineptr;

	while (1)
	{
		lineptr = read_line(prompt);
		if (!lineptr)
			break;
		int token_count = count_tokens(lineptr, delim);

		if (token_count <= 0)
		{
			free(lineptr);
			continue;
		}
		char *line_copy = strdup(lineptr);

		line_copy = strdup(lineptr);
		if (!line_copy)
		{
			perror("Error duplicating line");
			free(lineptr);
			continue;
		}

		tokens = tokenize_line(line_copy, delim, token_count);


		if (child_exit(tokens, line_copy, lineptr) == 0)
		{
			return (0);
		}
		/*app la fonction execution*/
		execution(tokens, 10)
		free(tokens);
		free(line_copy);
		free(lineptr);
	}
	return (0);
}
