#include "main.h"

/**
 * _fork_fun - Forks a child process and executes a command
 * @args: The arguments array
 * @envp: The environment array
 * @env: The current environment
 * @line: The command line
 * @pid: The process ID
 * @status: The exit status
 * Return: The exit status of the executed command
 */

int _fork_fun(char **args, char **envp, char **env, char *line, pid_t pid, int status)
{
	pid = fork();

	if (pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (_strcmp(args[0], "env") == 0)
		{
			_printenv(env);
			free(line);
			free(args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (execve(args[0], args, envp) == -1)
			{
				perror("Execve");
				free(line);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (status);
}

