#include "shell2.h"

/**
 * find_path - Find the PATH variable.
 * @environ: The global environment variable.
 *
 * Return: Array of pointers to PATH directories.
 */
char **find_path(char **environ)
{
	char *path, **directories, *delimiter;

	delimiter = ":";
	path = _getenv(environ, "PATH");
	directories = split_string(path, delimiter);
	return (directories);
}
