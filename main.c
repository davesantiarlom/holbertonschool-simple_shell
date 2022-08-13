#include "shell.h"

/**
 * main - A function that runs our shell.
 * @ac: The number of buffered arguments.
 * @av: The pointer to array of buffered arguments.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */

int main()
{
    int int_mode;
    char *buffer = NULL, **command = NULL;
    size_t buf_size = 0;
    ssize_t chars_read = 0;
    int counter=0;
    /*(void)ac;*/
    signal(SIGINT, handle);
    while(1){
        counter++;
        int_mode = isatty(STDIN_FILENO);

        if (int_mode == 1)
            write(STDOUT_FILENO, "$ ", 2);
        }

        chars_read = getline(&buffer, &buff_size, stdin);

        if (chars_read != EOF){
            command = split(buffer);

            if(_strcmp(command[0], "exit") == 0){
                shell_exit(command);
            }

            if(chars_read == -1){
                return (EXIT_FAILURE);
            }
        }
    return (EXIT_SUCCESS);
}
