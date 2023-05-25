#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command, char **env);
char **split_command(char *command);
void cleanup(char *command, char **user_command);

#endif /* SHELL_H */

