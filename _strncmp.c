#include "shell.h"
/**
 * _strncmp - compare two strings up to a specified number of characters
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 * Return: difference in ASCII values of the first differing characters
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return ('\0');
}
