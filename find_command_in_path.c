#include "main.h"

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
		full_path = malloc(strlen(dir) + strlen(command) + 2);
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
