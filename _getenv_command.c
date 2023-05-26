#include "shell.h"

/**
 *_getenv - Print all environment variables.
 *@env: The environment variable array.
 */
void _getenv_command(char **env)
{
	size_t i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

