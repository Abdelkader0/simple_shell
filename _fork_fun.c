#include "shell.h"

/**
 * _fork_fun - Creates a child process using fork()
 * @arg: Array of command and values path
 * @av: Array containing the program name
 * @env: Environment variables
 * @lineptr: Command line entered by the user
 * @np: Process ID
 * @c: Checker for adding new test
 *
 * Return: 0 on success
 */
int _fork_fun(char **arg, char **av, char **env,
		char *lineptr, int np, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
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
