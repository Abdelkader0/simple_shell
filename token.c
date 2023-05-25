#include "main.h"

/**
 * token - Get tokens from a string by splitting it.
 * @lineptr: User's command.
 * Return: Array of tokens.
 */
char **token(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == '')
			size++;
	}

	if ((size + 1) == _strlen(lineptr))
		return (NULL);

	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strtok(lineptr, " \n\t\r");
			for (i = 0; token != NULL; i++)
			{
				user_command[i] = token;
				token = _strtok(NULL, " \n\t\r");
			}

			user_command[i] = NULL;
			return (user_command);
}

