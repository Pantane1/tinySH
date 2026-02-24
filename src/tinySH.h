#ifndef TINYSH_H
#define TINYSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Function prototypes */
void print_prompt(void);
char **tokenize_input(char *input);
int execute_command(char **tokens);
int handle_builtins(char **tokens);

/* Built-in commands */
int shell_cd(char **tokens);
int shell_exit(char **tokens);

#endif
