#include "main.h"

/**
 * exit_command - Closes the simple_shell when exit command is called.
 * @arg: Pointer to the argument.
 * @lineptr: Standard input string.
 * @exit_status: Value of exit.
 *
 * This function frees memory and exits the program with the specified status.
 */
void exit_command(char **arg, char *lineptr, int exit_status)
{
	int status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(exit_status);
	}
	status = atoi(arg[1]);
	free(lineptr);
	free(arg);
	exit(status);
}

/**
 * getenv - Prints all environment variables.
 * @env: Array of environment variables.
 *
 * This function prints all environment variables to the standard output.
 */
void _getenv(char **env)
{
	size_t index = 0;
	while (env[index])
	{
		write(STDOUT_FILENO, env[index], _strlen(env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}

