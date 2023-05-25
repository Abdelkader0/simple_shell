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
