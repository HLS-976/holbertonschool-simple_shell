#include "main.h"

char *check_command(char *array[]);

/**
 * execution - Creates a child process to execute a program
 * @array: Array of strings containing the command and its arguments
 * @argv: Array of strings containing the program name and its arguments
 * @exit_code: Status of output code
 * Return: The exit code of the executed program, or -1 on error
 */
void execution(char *array[], char **argv, int *exit_code)
{
	pid_t pid;
	int status;
	char *command;

	command = check_command(array);
	if (!command) /* Checks if the command exist */
	{
		*exit_code = 127;
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], array[0]);
		return;
	}
	pid = fork();/* Creates a processus */
	if (pid < 0) /* Checks if the fork has failed*/
	{
		perror("Erreur lors de la création du processus");
		free(command);
		return;
	}
	else if (pid == 0) /* Performs the execution if the fork has worked*/
	{
		/* Performs the command in child process */
		if (execve(command, array, NULL) == -1)
		{
			perror("ERREUR");
			free(command);
			_exit(EXIT_FAILURE);/* Terminate the process */
		}
	}
	else
	{
		if (wait(&status) == -1)/* Waits the ending of the child process */
		{
			perror("Erreur lors de l'attente du processus fils");
			*exit_code = 1;
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			*exit_code = 2;
		}
		else
		{
			*exit_code = WEXITSTATUS(status);
		}
	}

	free(command);
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

	if (access(array[0], X_OK) == 0)
	{
		command = strdup(array[0]);
	}
	else
	{
		command = find_command_in_path(array[0]);
	}
	return (command);
}
