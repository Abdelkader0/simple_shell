#include "main.h"

/**
 * main - entry point of the program (Shell)
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environment variables
 * Return: exit status
 */
int main(int argc, char **argv, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, exit_status = 0, n = 0;
	(void)argc;

	while (1)
	{
		getcommand = _getline_command();
		if (getcommand)
		{
			pathValue++;
			user_command = _get_token(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
				_exit_command(user_command, getcommand, exit_status);
			if (!_strcmp(user_command[0], "env"))
				_getenv(env);
			else
			{
				n = _values_path(&user_command[0], env);
				exit_status = _fork_fun(user_command, argv, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_status);
		}
		free(getcommand);
	}
	return (exit_status);
}

