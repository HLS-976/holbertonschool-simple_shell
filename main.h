#ifndef MAIN_H
#define MAIN_H

/* Includes libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/* Prototypes */

char **tokenize_line(char *line, const char *delim, int token_count);

int count_tokens(const char *line, const char *delim);

int execution(char *argv[]);

int is_interactive(void);

int child_exit(char **tokens, char *line_copy, ssize_t nread);

char *find_command_in_path(char *command);

int is_interactive(void);

void handle_signal(int sig);

#endif
