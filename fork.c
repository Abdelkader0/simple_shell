#include "main.h"

/**
 * _fork_fun - function that creates a fork
 * @arg: command and values path
 * @av: array of strings containing program name
 * @env: environment variables
 * @lineptr: command line for the user
 * @np: process id
 * @c: checker for adding new test
 * Return: 0 on success
 */
int _fork_fun(char **argc, char **arvg, char **env, char *lineptr, int np, int c)
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
			return WEXITSTATUS(status);
	}

	return 0;
}

