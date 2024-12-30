#include "main.h"

void read_and_tokenize_line(const char *delim);
int process_line(char *lineptr, const char *delim);
void handle_tok(char **tokens, char *line_copy, char *lineptr);

/**
 *main - Shell program entry point
 *Return: always 0
 */

/* Point d'entrée principal du programme */
int main(void)
{
	const char *prompt = "(shell)-$ ";
	const char *delim = " \t\n";
	
	if (is_interactive())
	{
		while (1)
		{
			printf("%s", prompt);
			read_and_tokenize_line(delim);
		}
	}
	else
	{
		read_and_tokenize_line(delim);
	}

	return (0);
}
/**
 * read_and_tokenize_line - Reads an input line
 * @prompt: The prompt to display to the user
 * @delim: The delimiters used to tokenize the input
 */
/* Fonction pour lire et tokeniser la ligne d'entrée */
void read_and_tokenize_line(const char *delim)
{
	char *lineptr;

	lineptr	= read_line();

	if (!lineptr)
	{
		return;
	}

	if (process_line(lineptr, delim) == 0)
	{
		free(lineptr);
		return;
	}

	free(lineptr);
}
/**
 * process_line - Processes the input line by counting tokens
 * @lineptr: The input line to process
 * @delim: The delimiters used to tokenize the input
 * Return: 1 if the line is processed successfully, 0 otherwise
 */

/*Fonction pour traiter la ligne lue*/
int process_line(char *lineptr, const char *delim)
{
	int token_count;
	char *line_copy;
	char **tokens;

	token_count = count_tokens(lineptr, delim);

	if (token_count <= 0)
	{
		free(lineptr);
		return (0); /* Continuer la boucle*/
	}

	line_copy = strdup(lineptr);

	if (!line_copy)
	{
		perror("Error duplicating line");
		free(lineptr);
		return (0); /* Continuer la boucle*/
	}

	tokens = tokenize_line(line_copy, delim, token_count);

	if (!tokens)
	{
		free(lineptr);
		free(line_copy);
		return (0); /*Continuer la boucle*/
	}

	handle_tok(tokens, line_copy, lineptr);
	return (1); /*Ligne traitée*/
}

/**
 * handle_tok - Handles the tokens, checks for the exit command
 * @tokens: The array of tokens to handle
 * @line_copy: A duplicated copy of the input line
 * @lineptr: The original input line
 */

/* Fonction pour gérer les tokens */
void handle_tok(char **tokens, char *line_copy, char *lineptr)
{
	if (child_exit(tokens, line_copy, lineptr) == 0)
	{
		exit(0); /*Quitter le programme si la commande est "exit"*/
	}

	execution(tokens, 10);

	free(tokens);
	free(line_copy);

}

