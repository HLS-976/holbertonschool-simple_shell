#include "main.h"

/**
 * handle_signal - Handles signals like SIGINT and SIGTSTP
 * @sig: The signal number
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		fflush(stdout);
	}
	else if (sig == SIGTSTP)
	{
		printf("\nShell stopped. Type 'fg' to resume.\n");
		fflush(stdout);
	}
}
