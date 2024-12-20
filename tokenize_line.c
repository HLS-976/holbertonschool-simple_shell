// Fonction pour extraire les tokens et les stocker dans un tableau dynamique
char **tokenize_line(char *line, const char *delim, int token_count) {
    char **tokens = malloc((token_count + 1) * sizeof(char *));
    if (!tokens) {
        perror("Error allocating memory for tokens");
        return NULL;
    }

    int i = 0;
    char *token = strtok(line, delim);
    while (token) {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL; // Terminer avec NULL

    return tokens;
}