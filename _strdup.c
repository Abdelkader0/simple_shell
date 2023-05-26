#include "shell2.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if str is NULL or if
 *         memory allocation fails.
 */
char *_strdup(char *str)
{
	char *new_str;
	int i;

	if (str == NULL)
		return (NULL);

	new_str = malloc(_strlen(str) + 1);

	if (new_str == NULL)
		return (NULL);

	i = 0;

	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}

	new_str[i] = '\0';

	return (new_str);
}
