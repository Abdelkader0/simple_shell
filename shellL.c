#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * _exit_command - Exits the shell program
 *
 * Return: None
 */
void _exit_command(void)
{
	exit(0);
}

/**
 * _getenv_command - Gets the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable
 */
char *_getenv_command(const char *name)
{
	return getenv(name);
}

/**
 * _values_path - Retrieves the value of the PATH environment variable
 *
 * Return: The value of the PATH environment variable
 */
char *_values_path(void)
{
	return _getenv_command("PATH");
}

/**
 * _fork_fun - Creates a new process using fork()
 *
 * Return: The process ID of the child process
 */
pid_t _fork_fun(void)
{
	return fork();
}

/**
 * _strtok - Breaks a string into a series of tokens
 * @str: The string to be tokenized
 * @delim: The delimiter used to split the string
 *
 * Return: A pointer to the first token found in the string
 */
char *_strtok(char *str, const char *delim)
{
	return strtok(str, delim);
}

/**
 * execute_command - Executes the given command in a child process
 * @command: The command to execute
 *
 * Return: None
 */
void execute_command(const char *command)
{
	pid_t pid = _fork_fun();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		// Child process
		execlp(command, command, NULL);
		perror("Execution failed");
		exit(1);
	}
	else
	{
		// Parent process
		wait(NULL);
	}
}

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			// End-of-file condition (Ctrl+D)
			printf("\n");
			break;
		}

		// Remove newline character from the command
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			// Empty command, display prompt again
			continue;
		}

		execute_command(command);
	}

	return 0;
}
