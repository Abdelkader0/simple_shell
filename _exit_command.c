#include "main.h"

/**
 * _exit_command - Execute the exit command.
 * @args: The command and its arguments.
 * @lineptr: The line of input.
 * @_exit: The exit status.
 */

void _exit_command(char **args, char *lineptr, int _exit)
{
	free(lineptr);
	free(args);
	exit(_exit);
}
