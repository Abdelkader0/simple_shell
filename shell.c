#include "main.h"
/**
 * main - main arguments functions
 * @argc:count of argumnents
 * @argv: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	char **command_args = NULL;
	int pathValue = 0;
	int exit_status = 0;
	int n = 0;
	(void)argc;

	while (1)
	{
		command = get_line_command();
		if (command)
		{
			pathValue++;
			command_args = get_token(command);
			if (!command_args)
			{
				free(command);
				continue;
			}
			if ((!_strcmp(command_args[0], "exit")) && command_args[1] == NULL)
				execute_exit_command(command_args, command, exit_status);
			if (!_strcmp(command_args[0], "env"))
				execute_env_command(env);
			else
			{
				n = values_path(&command_args[0], env);
				exit_status = execute_fork(command_args, argv, env, command, pathValue, n);
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
