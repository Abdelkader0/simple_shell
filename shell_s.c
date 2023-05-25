#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point of the program.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 * @env: The environment variables.
 *
 * Return: 0 on success.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL;
	char **user_command = NULL;
	int should_exit = 0;
	(void)ac;
	(void)av;

	while (!should_exit)
	{
		printf("#cisfun$ ");

		getcommand = malloc(MAX_COMMAND_LENGTH * sizeof(char));
		if (!getcommand)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		if (fgets(getcommand, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		getcommand[strcspn(getcommand, "\n")] = '\0';

		user_command = split_command(getcommand);
		execute_command(user_command[0], env);
		cleanup(getcommand, user_command);
	}

	return (0);
}

/**
 * cleanup - Frees the memory allocated for
 * the command and user command arrays.
 *
 * @command: The command string.
 * @user_command: The array of strings.
 */
void cleanup(char *command, char **user_command)
{
	free(command);
	free(user_command);
}
