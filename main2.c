#include "shell2.h"

/**
 * main - Principal function.
 * @argc: The number of arguments.
 * @argv: Array of pointers to arguments.
 * @environ: Global variable.
 *
 * Return: 0.
 */
int main(int argc, char **argv, char **environ)
{
	char *input_line = NULL;
	char *delimiters = "\t \a\n";
	char *command;
	char **arguments;
	(void)argc;

	arguments = find_path(environ);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		input_line = read_line();
		argv = split_string(input_line, delimiters);
		command = args_path(argv, arguments);
		if (command == NULL)
			execute(argv);
		free(input_line);
		free(argv);
		free(command);
	}
	return (0);
}
