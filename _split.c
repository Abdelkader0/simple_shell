#include "shell.h"
/**
 * split_command - Splits the command into separate
 * words using space as the delimiter.
 * Returns an array of strings containing the individual words.
 *
 * @command: The command to split.
 *
 * Return: An array of strings representing the words in the command.
 */

char **split_command(char *command)
{
        int n = 0;
        char *token;
        char **user_command;

        user_command = malloc(MAX_COMMAND_LENGTH * sizeof(char *));
        if (!user_command)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }

        token = strtok(command, " ");
        while (token != NULL)
        {
                user_command[n++] = token;
                token = strtok(NULL, " ");
        }
        user_command[n] = NULL;

        return (user_command);
}
