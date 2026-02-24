#include "tinySH.h"

int execute_command(char **tokens) {
    /* First check if it's a built-in */
    int builtin_status = handle_builtins(tokens);
    if (builtin_status != -1) {
        return builtin_status; /* built-in executed (0 = continue, 1 = exit) */
    }

    pid_t pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Fork failed */
        perror("fork");
    } else {
        /* Parent process: wait for child to finish */
        int status;
        waitpid(pid, &status, 0);
    }
    return 1; /* continue */
}
