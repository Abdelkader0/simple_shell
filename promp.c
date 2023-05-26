#include "shell2.h"

/**
 * read_line - Read the command line.
 *
 * Return: Pointer to the line read from stdin.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int chars_read = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		exit(-1);
	}

	chars_read = strlen(line);
	line[chars_read - 1] = '\0';

	return (line);
}
