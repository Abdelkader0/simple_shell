#include "main.h"

/**
 * line_command - Prompt the user and read a line of input.
 * Return: The line of input from the user.
 */
char *line_command(void)
{
	char *lineptr = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	characters_read = getline(&lineptr, &buffer_size, stdin);
	if (characters_read == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

