#include "main.h"

/**
 * _getline_command - Read a line of input from the user.
 *
 * Return: The line of input read from the user, or NULL on failure or EOF.
 */

char *_getline_command()
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);

	if (nread == -1)
	{
		if (feof(stdin))
			return NULL;
		perror("getline");
		exit(EXIT_FAILURE);
	}

	return line;
}
