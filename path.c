#include "main.h"

/**
 * _get_path - Get the value of the PATH variable.
 * @env: Environment variables.
 * Return: Value of the PATH variable.
 */
char *path(char **env)
{
	size_t index = 0;
	char *path = NULL;

	for (index = 0; env[index] != NULL; index++)
	{
		if (_strncmp(env[index], "PATH=", 5) == 0)
		{
			path = env[index] + 5;

			break;
		}
	}

	return (path);
}

