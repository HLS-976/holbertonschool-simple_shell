#include "main.h"

char *check_command(char *argv[]);

/**
 * execution - Creates a child process to execute a program
 * @argv: Array of strings containing the program name and its arguments
 * Return: The exit code of the executed program, or -1 on error
 */

int execution(char *argv[])
{
	pid_t pid;
	int status;
	char *command;

	command = check_command(argv);
	if (!command)
	{
		perror("");
		return (-1);
	}
	pid = fork();/*Crée un processus fils*/
	if (pid < 0) /*Erreur lors du fork*/
	{
		perror("Erreur lors de la création du processus");
		return (-1);/*Retourne une erreur*/
	}
	else if (pid == 0) /*Code exécuté dans le fils*/
	{
		if (execve(command, argv, NULL) == -1)/*Exécute la commande*/
		{
			perror("Erreur lors de l'exécution de la commande");
			_exit(EXIT_FAILURE);/*Termine le fils proprement*/
		}
	}
	else
	{ /*Code exécuté dans le parent*/
		if (wait(&status) == -1)/*Attend la fin du fils*/
		{
			perror("Erreur lors de l'attente du processus fils");
			return (-1);/*Retourne une erreur*/
		}
		if (WIFEXITED(status))/*Vérifie si le fils s'est terminé normalement*/
		{
			return (WEXITSTATUS(status));/*Retourne le code de sortie du fils*/
		}
	}

	return (0);/*Retourne 0 si tout s'est bien passé*/
}

/**
 * check_command - checks if a command id executable
 * @argv: Array of strings representing the command and its arguments
 * Return: The command itself if it is executable, or the full path
 * of the command found in PATH. Returns NULL if the command is not found.
 */
char *check_command(char *argv[])
{
	char *command;

	if (access(argv[0], X_OK) == 0)
	{
		command = strdup(argv[0]);
	}
	else
	{
		command = find_command_in_path(argv[0]);
	}
	return (command);
}
