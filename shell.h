#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 100
extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
size_t _strcspn(const char *s1, const char *s2);
size_t _strspn(const char *s1, const char *s2);
char *_strchr(const char *s, int c);
int _putchar(char c);
void print_prompt(void);

char *_get_path(char **env);
char *_getline_command(void);
char **_get_token(char *lineptr);
void _exit_command(char **user_command, char *lineptr, int exit_status);
void _getenv_command(char **env);
int _values_path(char **arg, char **env);
int _fork_fun(char **command, char **av, char **env,
		char *input, int pathValue, int n);
char *_strtok(char *str, const char *delim);
#endif
