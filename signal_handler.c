#include "main.h"

/**
 * handle_signal - Handles signals like SIGINT and SIGTSTP
 * @sig: The signal number
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		fflush(stdout);
	}
}
