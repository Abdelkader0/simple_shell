#include "main.h"

/**
 * _exit_command - Handles the "exit" command in the shell.
 * @args: The arguments passed to the command.
 * @lineptr: The command line input.
 * @_exit: The exit code for the shell.
 */

void _exit_command(char **args, char *lineptr, int _exit)
{
	printf("Exiting shell...\n");
	free(lineptr);

	for (int i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
	exit(_exit);
}

