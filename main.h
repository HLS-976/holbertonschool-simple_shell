#ifndef MAIN_H
#define MAIN_H

/* Includes libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes */

char *read_line(const char *prompt);

char **tokenize_line(char *line, const char *delim, int token_count);

int count_tokens(const char *line, const char *delim) ;

#endif
