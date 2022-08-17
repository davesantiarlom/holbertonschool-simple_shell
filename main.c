#include "shell.h"

/**
 * main - A function that runs our shell.
 * @ac: The number of buffered arguments.
 * @av: The pointer to array of buffered arguments.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **tokens = NULL;
	size_t buffer_size = 0;
	ssize_t chars_read = 0;
	int counter = 0;

	(void)ac;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		chars_read = getline(&buffer, &buffer_size, stdin);
		if (chars_read == EOF)
		{
		      	if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			tokens = split(buffer, " \0");
			free(buffer);
			if (_strcmp(tokens[0], "exit") != 0)
				shell_exit(tokens);
			create_child(tokens, av[0], env, counter);
		}
		fflush(stdin);
		buffer = NULL, buffer_size = 0;
	}/*End While*/
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
