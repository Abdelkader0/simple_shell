#include "shell.h"

/**
 * main - Main function to handle shell execution
 * @ac: Number of arguments
 * @av: Array of arguments
 * @env: Array of environment variables
 * Return: Exit status
 */
char *_get_path(char **env);
char *_getline_command(void);
char **_get_token(char *lineptr);
void _exit_command(char **user_command, char *lineptr, int exit_status);
void _getenv_command(char **env);
int _values_path(char **arg, char **env);
int _fork_fun(char **command, char **av, char **env,
		char *input, int pathValue, int n);
char *_strtok(char *str, const char *delim);

int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;

	while (1)
	{
		print_prompt();
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
			if (!_strcmp(user_command[0], "exit") && user_command[1] == NULL)
				_exit_command(user_command, getcommand, _exit);
			if (!_strcmp(user_command[0], "env"))
				_getenv_command(env);
			else
			{
				n = _values_path(&user_command[0], env);
				_exit = _fork_fun(user_command, av, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(getcommand);
	}
	return (_exit);
}
