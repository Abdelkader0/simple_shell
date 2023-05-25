#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024


/* Function Declarations */
void display_prompt();
void execute_command(char* command);



#endif /* SHELL_H */

