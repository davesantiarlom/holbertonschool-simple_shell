#include "shell.h"

/**
 * create_child - A function that creates a sub process.
 * @command: The pointer to tokenized command
 * @buffer: The pointer to the buffer of shell.
 * @env: The pointer to the enviromental variables.
 * @counter: Number of executed counter.
 * Return: Nothing.
 */
int create_child(char **command, char *buffer, char **env, int counter)
{
	int pid;
  int status;

	if (*command == NULL)
		return (-1);

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1); 
	}

	if (pid == 0)
	{
		if (execve(*command, command, env) == -1)
		{
			print_error(command[0], counter, env);
			free(buffer);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	return (0);
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @buffer:User buffer
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *buffer, int counter, char **argv)
{
	char c;

	c = counter + '0';
	write(STDOUT_FILENO, buffer, _strlen(buffer));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
