#include "tinySH.h"

int main(void) {
    char input[MAX_INPUT_SIZE];
    char **tokens;
    int status = 1; /* run until exit */

    while (status) {
        print_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; /* EOF (Ctrl+D) */
        }

        /* Remove trailing newline */
        input[strcspn(input, "\n")] = '\0';

        /* Skip empty lines */
        if (strlen(input) == 0) {
            continue;
        }

        tokens = tokenize_input(input);
        if (tokens[0] != NULL) {
            status = execute_command(tokens);
        }

        /* Free token array */
        free(tokens);
    }

    return 0;
}

void print_prompt(void) {
    printf("tinySH> ");
    fflush(stdout);
}

char **tokenize_input(char *input) {
    char **tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token;
    int position = 0;

    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = malloc(strlen(token) + 1);
        strcpy(tokens[position], token);
        position++;

        if (position >= MAX_NUM_TOKENS) {
            fprintf(stderr, "Too many tokens\n");
            break;
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL; /* terminate the array */
    return tokens;
}
