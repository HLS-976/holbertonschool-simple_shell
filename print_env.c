#include "main.h"

/**
 * print_env - Loops through all environment variables and prints them
 */


void print_env(void)
{
	char **env;

	/* Iterates through the environ array and print each element of this */
	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}
