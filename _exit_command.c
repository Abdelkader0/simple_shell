#include "shell.h"

/**
 *_exit_command - Handle the "exit" command
 *@user_command: Array of command tokens
 *@lineptr: Pointer to the input command line
 *@exit_status: Exit status value
 */
void _exit_command(char **user_command, char *lineptr, int exit_status)
{
	if (user_command)
		free(user_command);
	if (lineptr)
		free(lineptr);
	exit(exit_status);
}
