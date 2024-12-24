#include "main.h"

/**
 * execution - Creates a child process to execute a program
 * @argv: Array of strings containing the program name and its arguments
 * @token_count: The number of tokens in argv
 * Return: The exit code of the executed program, or -1 on error
 */

int execution(char *argv[], int token_count)
{
	pid_t pid;
	int status;

	(void)token_count;

	pid = fork();/*Crée un processus fils*/
	if (pid < 0) /* Erreur lors du fork*/
	{
		perror("Erreur lors de la création du processus");
		return (-1);/*Retourne une erreur*/
	}
	else if (pid == 0) /* Code exécuté dans le fils*/
	{
		if (execve(argv[0], argv, NULL) == -1)/*Exécute la commande*/
		{
			perror("Erreur lors de l'exécution de la commande");
			_exit(EXIT_FAILURE);/*Termine le fils proprement*/
		}
	}
	else
	{ /* Code exécuté dans le parent*/
		if (wait(&status) == -1)/* Attend la fin du fils*/
		{
			perror("Erreur lors de l'attente du processus fils");
			return (-1);/*Retourne une erreur*/
		}
		if (WIFEXITED(status))/* Vérifie si le fils s'est terminé normalement*/
		{
			return (WEXITSTATUS(status));/*Retourne le code de sortie du fils*/
		}
	}

	return (0);/*Retourne 0 si tout s'est bien passé*/
}
