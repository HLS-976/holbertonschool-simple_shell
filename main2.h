#ifndef MAIN2_H
#define MAIN2_H

/* Includes libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */

char *read_line(const char *prompt);

char **tokenize_line(char *line, const char *delim, int token_count);

int count_tokens(const char *line, const char *delim);

int execution(char *argv[], int token_count);

char *find_command_path(char *cmd);

int child_exit(char **tokens, char *line_copy, char *lineptr);



void read_and_tokenize_line(const char *prompt, const char *delim);
int process_line(char *lineptr, const char *delim);
void handle_tok(char **tokens, char *line_copy, char *lineptr, int token_count);

#endif
