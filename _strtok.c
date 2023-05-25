#include "shell.h"

/**
 * _strtok - Breaks the string s1 into tokens and null-terminates them.
 * Delimiter characters at the beginning and end.
 * @str: String to tokenize
 * @delim: String with the character that delimits str
 * Return: The first/next token if possible, a null pointer otherwise
 **/
char *_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + strspn(p, delim);
	p = str + strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}

/**
 * _strcspn - Computes the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters not from the
 * string pointed to by s2.
 * @s1: String to check
 * @s2: String used for comparison
 * Return: The length of the segment
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (strchr(s2, *s1))
			return (ret);
		s1++, ret++;
	}
	return (ret);
}

/**
 * _strspn - Computes the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters from the string
 * pointed to by s2.
 * @s1: String to compute the length
 * @s2: String delimiter
 * Return: The length of the segment
 **/
size_t _strspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1 && strchr(s2, *s1++))
		ret++;
	return (ret);
}

/**
 * _strchr - Locates the first occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @s: String
 * @c: Character
 * Return: A pointer to the located character, or a null pointer
 * if the character does not occur in the string
 **/
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}
