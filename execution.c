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
		perror("Command not found");
		return (-1);
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
		if (execve(command, argv, NULL) == -1)/*Exécute la commande*/
		{
			perror("Erreur lors de l'exécution de la commande");
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

/*
 *
 *
 *
 */
char *check_command(char *argv[])
{
	char *command;

	if (access(argv[0], X_OK) == 0)
	{
		command = argv[0];
	}
	else
	{
		command = find_command_in_path(argv[0]);
	}
	return (command);
}
