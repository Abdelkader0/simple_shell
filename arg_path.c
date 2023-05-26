#include "shell2.h"

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int m,  j;

	for (m = 0; dest[m] != '\0'; m++)
	{ }

	for (j = 0; src[j] != '\0'; j++, m++)
		dest[m] = src[j];

	dest[m] = '\0';
	return (dest);
}

/**
 * args_path - Concatenates the arguments.
 * @parse: The array of arguments.
 * @new: The array of directories to search in.
 *
 * Return: The concatenated string, or NULL if not found.
 */
char *args_path(char **parse, char **new)
{
	char *total, **cat;
	int m, j, k;
	struct stat status;

	for (m = 0; new[m]; m++)
	{
		total = malloc(60);
		_strcat(total, new[m]);
		_strcat(total, "/");
		_strcat(total, parse[0]);

		if (stat(total, &status) == 0)
		{
			for (k = 0; parse[k] != NULL; k++)
				;
			cat = malloc(sizeof(char *) * (k + 1));
			cat[k] = NULL;
			cat[0] = _strdup(total);

			for (j = 1; parse[j]; j++)
				cat[j] = _strdup(parse[j]);
			execute(cat);
			return (total);
		}
		free(total);
	}
	return (NULL);
}
