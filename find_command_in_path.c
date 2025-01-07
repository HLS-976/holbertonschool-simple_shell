#include "main.h"

int _strlen(char *s);
/**
 *find_command_in_path - find the full path  of a command
 *@command: the command to find
 *Return: full path of the command if found, NULL otherwise
 */

char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir;
	char *full_path;
	struct stat st;

	if (!path_copy)
	{
		perror("Error duplicating PATH");
		return (NULL);
	}
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (!full_path)
		{
			perror("Error allocating memory for full path");
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 *_strlen - calculates the length of the string
 *@s: the string to measure
 *Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
