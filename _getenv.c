#include "shell2.h"

/**
 * get_value - Get the value after the '=' character in a string.
 * @str: The string to process.
 *
 * Return: Pointer to the value string.
 */

char *get_value(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;
	return (str + i + 1);
}

/**
 * compare_strings - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 1 if the strings are equal, 0 otherwise.
 */

int compare_strings(char *str1, char *str2)
{
	int i;

	for (i = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] != str1[i])
			return (0);
	}
	return (1);
}

/**
 * _getenv - Get the value of an environment variable.
 * @environ: The environment variables array.
 * @name: The name of the variable to search for.
 *
 * Return: The value of the variable, or NULL if not found.
 */

char *_getenv(char **environ, char *name)
{
	int i, j;
	char *varname, *value;

	for (i = 0; environ[i]; i++)
	{
		varname = malloc(1024);

		for (j = 0; environ[i][j] != '='; j++)
			varname[j] = environ[i][j];

		if (compare_strings(varname, name))
		{
			value = get_value(environ[i]);
			free(varname);
			return (value);
		}
		free(varname);
	}
	return (NULL);
}
