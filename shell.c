#include "main.h"
/**
 * main - Shell program entry point
 * Return: 0 si le programme s'exécute avec succès, -1 en cas d'erreur
 */
int main(void)
{
	const char *prompt = "(shell)-$";
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

		char *line_copy = strdup(lineptr);
		if (!line_copy)
		{
			perror("Error duplicating line");
			free(lineptr);
			continue;
		}
<<<<<<< HEAD

		char **tokens = tokenize_line(line_copy, delim, token_count);
=======
		char **tokens = tokenize_line(line_copy, delim, token_count);

>>>>>>> David
		if (!tokens)
		{
			free(lineptr);
			free(line_copy);
			continue;
		}
<<<<<<< HEAD

		if (strcmp(tokens[0], "exit") == 0) 
		{
			free(tokens);
			free(line_copy);
			free(lineptr);
			return (0);
		}

		execution(tokens, 10);

=======
		if (child_exit(tokens, line_copy, lineptr) == 0)
		{
			return (0);
		}
		/*app la fonction execution*/
		execution(tokens, 10);
>>>>>>> David
		free(tokens);
		free(line_copy);
		free(lineptr);
	}
	return (0);
}
