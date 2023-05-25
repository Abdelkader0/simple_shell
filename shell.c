#include "main.h"

/**
 * main - Entry point for the simple shell program
 *
 * Description:
 * The main function serves as the entry point for the simple shell program.
 * It displays a prompt, reads user input, and executes the corresponding
 * commands. The shell supports basic command execution, including built-in
 * commands like "cd" and "exit", as well as executing external programs.
 * It provides a basic command-line interface for users to interact with the
 * shell environment.
 *
 * Return:
 * The main function returns an integer value indicating the exit status of the
 * shell program. By convention, a return value of 0 typically indicates
 * successful termination, while non-zero values represent various error codes
 * or abnormal terminations.
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		printf("#cisfun$ ");

		line = _getline_command();

		if (line == NULL)
		{
			printf("\n");
			break;
		}

		args = _get_token(line);
		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}

		if (_strcmp(args[0], "exit") == 0)
		{
			_exit_command(args, line, 0);
			free(args);
			continue;
		}

		status = _fork_fun(args, environ, environ, line, 0, 0);

		free(args);
		free(line);
	}

	return (status);
}
