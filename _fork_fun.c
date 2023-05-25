#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * _fork_fun - Creates a new process using fork()
 *
 * Return: The process ID of the child process
 */
pid_t _fork_fun(void)
{
	return (fork());
}

