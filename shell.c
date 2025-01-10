#include "main.h"

int read_and_tokenize_line(const char *delim, char **argv, int *exit_code);
int process_line(char *lineptr, const char *delim,
		char **argv, int *exit_code);

/**
 *main - Shell program entry point
 *@ac: Number of arguments
 *@argv: Array of argument strings
 *Return: Always 0
 */
int main(int ac, char **argv)
{
	const char *prompt = "(shell)-$ ";
	const char *delim = " \t\n";
	int exit_code;

	(void)ac;
	exit_code = 0;

	signal(SIGINT, handle_signal);
	signal(SIGTSTP, SIG_IGN);

	if (is_interactive()) /* Interactive mode */
	{
		while (1)
		{
			printf("%s", prompt);
			/* Stop the loop if te return is -1 */
			if (read_and_tokenize_line(delim, argv, &exit_code) == -1)
				break;
		}
	}
	else /* Non-interactive mode */
	{
		read_and_tokenize_line(delim, argv, &exit_code);
	}

	return (exit_code);
}

/**
 * read_and_tokenize_line - Reads an input line
 * @delim: The delimiters used to tokenize the input
 * @argv: Array of argument strings
 * @exit_code: Status of output code
 * Return: always 0
 */
int read_and_tokenize_line(const char *delim, char **argv, int *exit_code)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;

	nread = getline(&lineptr, &n, stdin); /* get the line and stores it */

	if (nread == -1)
	{
		printf("\n");
		free(lineptr);
		return (-1);
	}

	if (strncmp(lineptr, "exit", 4) == 0)
	{ /* exit the progam */
		free(lineptr);
		exit(*exit_code);
	}

	if (strncmp(lineptr, "env", 3) == 0)
	{
		print_env(); /* Print all of environment variables */
		free(lineptr);
		return (-1);
	}

	if (process_line(lineptr, delim, argv, exit_code) == -1)
	{
		free(lineptr);
		return (-1);
	}
	free(lineptr);
	return (0);
}
/**
 * process_line - Processes the input line by counting tokens
 * @lineptr: The input line to process
 * @delim: The delimiters used to tokenize the input
 * @argv : Array of argument strings
 * @exit_code: Status of output code
 * Return: 1 if the line is processed successfully, 0 otherwise
 */
int process_line(char *lineptr, const char *delim, char **argv, int *exit_code)
{
	int token_count;
	char *line_copy;
	char **tokens;

	token_count = count_tokens(lineptr, delim);

	if (token_count <= 0) /* Count the number og character of the input line */
	{
		return (-1);
	}

	line_copy = strdup(lineptr); /* Duplicates and stores the copy */

	if (!line_copy)
	{
		perror("Error duplicating line");
		return (-1);
	}

	/* Performs the divide of line copy */
	tokens = tokenize_line(line_copy, delim, token_count);
	if (!tokens)
	{
		free(line_copy);
		return (-1);
	}

	/* throws the execution of command */
	execution(tokens, argv, exit_code);

	free(tokens);
	free(line_copy);
	return (0);
}
