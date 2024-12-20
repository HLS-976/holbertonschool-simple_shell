#include "main.h"

// Fonction principale
int main(void) {
    const char *prompt = ">>> ";
    const char *delim = " \t\n"; // Espaces, tabulations et nouvelles lignes
    char *lineptr;

    while (1) {
        lineptr = read_line(prompt);
        if (!lineptr)
            break;

        int token_count = count_tokens(lineptr, delim);
        if (token_count <= 0) {
            free(lineptr);
            continue;
        }

        char *line_copy = strdup(lineptr);
        if (!line_copy) {
            perror("Error duplicating line");
            free(lineptr);
            continue;
        }

        char **tokens = tokenize_line(line_copy, delim, token_count);
        if (!tokens) {
            free(lineptr);
            free(line_copy);
            continue;
        }

        free(tokens);
        free(line_copy);
        free(lineptr);
    }

    return 0;
}
