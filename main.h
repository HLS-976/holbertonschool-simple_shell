#ifndef MAIN_H
#define MAIN_H

/* Includes libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */

char *read_line(void);

char **tokenize_line(char *line, const char *delim, int token_count);

int count_tokens(const char *line, const char *delim);

int execution(char *argv[], int token_count);

int is_interactive(void);

int child_exit(char **tokens, char *line_copy, char *lineptr, ssize_t nread);

int is_interactive(void);

#endif
