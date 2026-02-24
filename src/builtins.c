#include "tinySH.h"

int handle_builtins(char **tokens) {
    if (strcmp(tokens[0], "exit") == 0) {
        return shell_exit(tokens);
    } else if (strcmp(tokens[0], "cd") == 0) {
        return shell_cd(tokens);
    }
    return -1; /* not a built-in */
}

int shell_cd(char **tokens) {
    char *path = tokens[1] ? tokens[1] : getenv("HOME");
    if (path == NULL) {
        fprintf(stderr, "cd: no home directory\n");
        return 1;
    }
    if (chdir(path) != 0) {
        perror("cd");
    }
    return 1; /* continue */
}

int shell_exit(char **tokens) {
    return 0; /* signal main loop to exit */
}
