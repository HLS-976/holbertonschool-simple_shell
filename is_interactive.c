#include "main.h"

/**
 * is_interactive - Checks if the shell is in interactive mode
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */


int is_interactive(void)
{
	return (isatty(fileno(stdin)));
}
