#include "shell2.h"

/**
 * execute - Execute the commands.
 * @args: Array of pointers to arguments.
 *
 * Return: Always 0.
 */
int execute(char **args)
{
	pid_t pid;
	int sts;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(&sts);
	}
	else
		perror("Error:");

	return (0);
}
