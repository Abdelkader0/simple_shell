#ifndef SHELL2_H
#define SHELL2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

/* Function prototypes */
char **find_path(char **environ);
char *read_line(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **split_string(char *str, char *delimiter);
int execute(char **args);
char *find_executable(char **args, char **directories);
char *_getenv(char **environ, char *dirname);
unsigned int _strlen(char *s);
char *_strdup(char *str);
void _puts(char *str);
int _putchar(char c);
char *args_path(char **parse, char **new);

#endif /* SHELL2 */
