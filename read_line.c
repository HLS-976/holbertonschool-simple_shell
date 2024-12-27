#include "main.h"

/**
 * read_line - Reads a line from the user with a prompt
 * @prompt: The prompt to display to prompt the user for a line
 * Return: A pointer to the line read, or NULL on error
 */

/* Fonction pour lire une ligne depuis l'utilisateur*/

char *read_line(const char *prompt)
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t chars_read;

	printf("%s", prompt);

	chars_read = getline(&lineptr, &length, stdin);

	if (chars_read == -1)
	{
		perror("Error reading line");
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}
