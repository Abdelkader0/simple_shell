#include "main.h"

/**
 * _exit_command - Closes the simple_shell when the command is executed.
 * @args: Pointer to the array.
 * @lineptr: Pointer to the input.
 * @exit_status: Value of the exit status.
 * Return: None.
 */
void _exit_command(char **args, char *lineptr, int exit_status)
{
	int status = 0;

	if (!args[1])
	{
		free(lineptr);
		free(args);
		exit(exit_status);
	}

	status = atoi(args[1]);

	free(lineptr);
	free(args);
	exit(status);
}

/**
 * _getenv - Prints all environment variables.
 * @env: Array of environment variables.
 * Return: None.
 */
void _getenv(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

