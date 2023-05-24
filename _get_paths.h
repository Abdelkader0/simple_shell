#include "main.h"

/**
 * _get_path - get variable PATH to use it.
 * @env: environment variable array
 * @prefix: prefix string to match in the environment variable
 * Return: value of matching environment variable, or NULL if not found.
 */
char *_get_path(char **env, const char *prefix)
{
    size_t index = 0, var = 0, count = 0;
    char *path = NULL;

    for (index = 0; env[index] != NULL; index++)
    {
        if (_strncmp(env[index], prefix, _strlen(prefix)) == 0)
        {
            count = _strlen(prefix);
            break;
        }
    }

    if (env[index] == NULL)
        return NULL;

    for (var = count; env[index][var]; var++)
        count++;

    path = malloc(sizeof(char) * (count + 1));
    if (path == NULL)
        return NULL;

    for (var = count = 0; env[index][var]; var++, count++)
        path[count] = env[index][var];

    path[count] = '\0';
    return path;
}
