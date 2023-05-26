# Shell Project

This project is a basic implementation of a shell in the C programming language. It aims to replicate some of the functionalities and behaviors of a shell.

## How to Use

To use the shell, follow these steps:

1. Compile the source code by running the command: `$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

2. Run the shell by executing the command: `$ ./hsh`

3. Once the shell is running, you can enter various commands supported by the shell.

## Supported Commands

The shell supports the following commands:

1. Most bash shell commands that end with `/bin/the_command`
2. `exit`: Exit the shell.
3. `clear`: Clear the terminal screen.
4. `ls`: List files and directories.
5. Commands with arguments are also supported.

## Functions Used

The shell implementation utilizes various functions, including:

1. `access`: Check if a file exists.
2. `execve`: Execute a program.
3. `exit`: Terminate the shell.
4. `fflush`: Flush the output buffer.
5. `free`: Free allocated memory.
6. `isatty`: Check if a file descriptor refers to a terminal.
7. `malloc`: Allocate memory dynamically.
8. `perror`: Print error message.
9. `read`: Read input from the user.
10. `write`: Write output to the terminal.
11. `fork`: Create a child process.
12. `waitpid`: Wait for the child process to finish.
13. `_strspn`: Get the length of a prefix substring.
14. `_strchr`: Find the first occurrence of a character in a string.

## Recommendations

Feel free to explore and modify this shell implementation according to your requirements. Experiment with adding new functionalities, handling edge cases, and improving the user experience.
