#include "main.h"

/**
 * main - main arguments function
 * @argc: count of arguments
 * @argv: arguments
 * @env: environment
 * Return: exit status
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	char **command_args = NULL;
	int pathValue = 0;
	int exit_status = 0;
	int n = 0;
	(void) argc;

	while (1)
	{
		command = line_command();
		if (command)
		{
			pathValue++;
			command_args = token(command);
			if (!command_args)
			{
				free(command);
				continue;
			}
			if ((!_strcmp(command_args[0], "exit")) && command_args[1] == NULL)
				_exit_command(command_args, command, exit_status);
			if (!_strcmp(command_args[0], "env"))
				_getenv_command(env);
			else
			{
				n = _values_path(&command_args[0], env);
				exit_status = _fork_fun(command_args, argv, env, command, pathValue, n);
				if (n == 0)
					free(command_args[0]);
			}
			free(command_args);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_status);
		}
		free(command);
	}

	return (exit_status);
}
