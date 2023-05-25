#include "shell.h"
/**
 * cleanup - Frees the memory allocated for
 * the command and user command arrays.
 *
 * @command: The command string.
 * @user_command: The array of strings.
 */
void cleanup(char *command, char **user_command)
{
        free(command);
        free(user_command);
}
    
