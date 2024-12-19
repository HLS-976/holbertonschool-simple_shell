#include "main.h"

int main(int ac, char **av)
{
        char *prompt = "$ ";
        char *lineptr;
        size_t length = 0;
        ssize_t chars_read;

        (void) ac; (void) av;

        while (1)
        {
                printf("%s", prompt);
                chars_read = getline(&lineptr, &length, stdin);

                if (chars_read == - 1)
                {
                        printf("error exit shell..\n");
                        return (-1);
                }
                printf("%s\n", lineptr);

                free(lineptr);
        }
        return (0);
}
