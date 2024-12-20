// Fonction pour compter le nombre de tokens dans une ligne
int count_tokens(const char *line, const char *delim) {
    int count = 0;
    char *line_copy = strdup(line);
    if (!line_copy) {
        perror("Error duplicating line");
        return -1;
    }

    char *token = strtok(line_copy, delim);
    while (token) {
        count++;
        token = strtok(NULL, delim);
    }

    free(line_copy);
    return count;
}
