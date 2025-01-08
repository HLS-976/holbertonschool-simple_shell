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

extern char **environ;

char **tokenize_line(char *line, const char *delim, int token_count);

int count_tokens(const char *line, const char *delim);

int execution(char *array[], char **argv);

int is_interactive(void);

char *find_command_in_path(char *command);

int is_interactive(void);

void handle_signal(int sig);

#endif
