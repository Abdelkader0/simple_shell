#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[src_len] != '\0')
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	dest[dest_len] = '\0';

	return (dest);
}
