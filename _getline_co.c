#include "shell.h"

/**
 * _getline_command - Prints the shell prompt "#cisfun$ " and reads user input
 *
 * Return: Line of string input from the user
 */
char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#:)$ ", 0);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

