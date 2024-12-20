#include "main.h"

// Fonction pour lire une ligne depuis l'utilisateur
char *read_line(const char *prompt) {
    char *lineptr = NULL;
    size_t length = 0;

    printf("%s", prompt);
    ssize_t chars_read = getline(&lineptr, &length, stdin);

    if (chars_read == -1) {
        perror("Error reading line");
        free(lineptr);
        return NULL;
    }

    return lineptr;
}
