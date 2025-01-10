#include "main.h"

/**
 * print_env - Loops through all environment variables and prints them
 */


void print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}
