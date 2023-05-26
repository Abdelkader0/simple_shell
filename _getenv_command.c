#include "shell.h"

/**
 * _getenv_command - Print all environment variables.
 * @env: The environment variable array.
 * Return: The value of the environment variable if found, NULL otherwise
 */
void _getenv_command(char **env)
{
	size_t i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

