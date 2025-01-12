#include "main.h"

/**
 *find_command_in_path - find the full path  of a command
 *@command: the command to find
 *Return: full path of the command if found, NULL otherwise
 */
char *find_command_in_path(char *command)
{
	char *path = _getenv("PATH"); /* Gets the PATH environment variable */
	char *path_copy;
	char *dir;
	char *full_path;
	struct stat st;

	path_copy = strdup(path); /* Duplicates the path to manipulate it */
	if (!path_copy)
	{
		perror("Error duplicating PATH");
		return (NULL);
	}
	dir = strtok(path_copy, ":"); /* Divides the path with delimiter specified */
	while (dir)
	{
		/* Allocates the dynamic memory to stores the final path */
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			perror("Error allocating memory for full path");
			free(path_copy);
			return (NULL);
		}
		/* Associates the command given with tokens of dir to build a new path */
		sprintf(full_path, "%s/%s", dir, command);
		/* Checks if the new path exist and is executable */
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path); /* Returns the new path */
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
