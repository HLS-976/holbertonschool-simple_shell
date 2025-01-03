#include "main.h"

/**
 * read_line - Reads a line from the user with a prompt
 * Return: A pointer to the line read, or NULL on error
 */

/* Fonction pour lire une ligne depuis l'utilisateur*/

char *read_line(void)
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t chars_read;

	chars_read = getline(&lineptr, &length, stdin);

	if (chars_read == -1)
	{
		perror("Error reading line");
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}
