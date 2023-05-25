#include "shell.h"

/**
 * execute_command - Executes the given command
 * by forking a child process and using execve.
 * Waits for the child process to finish executing.
 *
 * @command: The command to execute.
 * @env: The environment variables.
 */

void execute_command(char *command, char **env)
{
        pid_t pid;

        pid = fork();
        if (pid < 0)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
                if (execve(command, &command, env) < 0)
                {
                        perror("execve");
                        exit(EXIT_FAILURE);
                }
        }

        waitpid(pid, NULL, 0);
}
