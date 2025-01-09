#include "main.h"

char *check_command(char *array[]);

/**
 * execution - Creates a child process to execute a program
 * @array: Array of strings containing the command and its arguments
 * @argv: Array of strings containing the program name and its arguments
 * Return: The exit code of the executed program, or -1 on error
 */

int execution(char *array[], char **argv, int *exit_code)
{
	pid_t pid;
	int status;
	char *command;

	command = check_command(array);
	if (!command)
	{
		*exit_code = 2;
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], array[0]);
		return (0);
	}
	pid = fork();/*Crée un processus fils*/
	if (pid < 0) /*Erreur lors du fork*/
	{
		perror("Erreur lors de la création du processus");
		free(command);
		return (-1);/*Retourne une erreur*/
	}
	else if (pid == 0) /*Code exécuté dans le fils*/
	{
		if (execve(command, array, NULL) == -1)/*Exécute la commande*/
		{
			perror("ERREUR");
			free(command);
			_exit(EXIT_FAILURE);/*Termine le fils proprement*/
		}
	}
	else
	{ /*Code exécuté dans le parent*/
		if (wait(&status) == -1)/*Attend la fin du fils*/
		{
			perror("Erreur lors de l'attente du processus fils");
			free(command);
			return (-1);/*Retourne une erreur*/
		}
		if (WIFEXITED(status))/*Vérifie si le fils s'est terminé normalement*/
		{
			free(command);
			return (WEXITSTATUS(status));/*Retourne le code de sortie du fils*/
		}
	}

	free(command);
	return (0);/*Retourne 0 si tout s'est bien passé*/
}

/**
 * check_command - Checks if a command id executable
 * @array: Array of strings representing the command and its arguments
 * Return: The command itself if it is executable, or the full path
 * of the command found in PATH. Returns NULL if the command is not found.
 */
char *check_command(char *array[])
{
	char *command;

	if (strchr(array[0], '/'))
	{
		if (access(array[0], X_OK) == 0)
		{
			command = strdup(array[0]);
		}
	}
	else
	{
		command = find_command_in_path(array[0]);
	}
	return (command);
}
