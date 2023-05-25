#include "main.h"

/**
 * fork_fun - Creates a fork and executes a command.
 * @arg: Command and path values.
 * @av: Name of the program.
 * @env: Environment variables.
 * @lineptr: Command line for the user.
 * @np: Process ID.
 * @c: Checker for new test.
 * Return: 0 on success.
 */
int fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0])
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
