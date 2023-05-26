#include "shell.h"
/**
 * _strlen - calculate the length of a string
 * @s: input string
 * Return: length of the string
 */
unsigned int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
