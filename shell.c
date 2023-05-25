#include "shell.h"

/*
 * Displays the prompt for the shell.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/*
 * Executes the given command by forking a new process and using execlp.
 *
 * Parameters:
 *   command - The command to be executed.
 */

void execute_command(char *command)
{
	command[strcspn(command, "\n")] = '\0';

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * The entry point of the shell program.
 * Displays the prompt, reads user input, and executes the given command.
 *
 * Returns:
 *   int - The exit status of the shell.
 */

int main(void)
{
	char command[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		execute_command(command);
	}

	return ('\0');
}
