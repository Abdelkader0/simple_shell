#include "shell.h"

/**
 * _realloc - Reallocate memory.
 * @ptr: Pointer to the memory to reallocate.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_mem;
	unsigned int i;

	if (ptr == NULL)
	{
		new_mem = malloc(new_size);
		return (new_mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_mem = malloc(new_size);

	if (new_mem == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
	{
		new_mem[i] = ((char *)ptr)[i];
	}

	free(ptr);

	return (new_mem);
}

/**
 * split_string - Split a string into tokens.
 * @line: The string to split.
 * @delim: The delimiter characters.
 *
 * Return: Array of pointers to tokens.
 */
char **split_string(char *line, char *delim)
{
	char **tokens;
	int bufsize = 1024;
	int i = 0;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
		exit(99);

	tokens[i] = strtok(line, delim);
	i++;
	while (1)
	{
		tokens[i] = strtok(NULL, delim);
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = _realloc(tokens, bufsize, bufsize * sizeof(char *));
			if (!tokens)
				exit(98);
		}
		if (tokens[i] == NULL)
			break;
		i++;
	}
	return (tokens);
}
