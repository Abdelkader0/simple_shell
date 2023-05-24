#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
/* using for Strings */
int _strncmp(const char s1, const chars2, size_t n);
size_t _strlen(const char s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
size_t _strlen(const char s);
int _putchar(char c);
char *_get_path(char *env[], const char *prefix);
/* */
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **arg, char *lineptr, int _exit);
int _fork_fun(char **arvg, char **av, char **env, char *lineptr, int nQp,
		int c);
char *lineptr(int np, int c);
char *_strtok(char *str, const char *delim);

#endif
