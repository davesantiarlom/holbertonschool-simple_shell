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
		if (strncmp(*command, "./", 2) != 0 && strncmp(*command, "/", 1) != 0)
			path_command(command);

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

/**
 * path_command -  Search In $PATH For Excutable Command
 * @command: Parsed buffer
 * Return: 1  Failure  0  Success.
 */
int path_command(char **command)
{
	char *path, *value, *command_path;
	struct stat buf;
	path = getenv("PATH");
	value = strtok(path, ":");
	while (value != NULL){
		command_path = build(*command, value);
		if (stat(command_path, &buf) == 0){
			*command = strdup(command_path);
			free(command_path);
			free(path);
			return (0);
		}
		free(command_path);
		value = strtok(NULL, ":");
	}
	free(path);
	return (1);
}

/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value){
	char *command;
	size_t len;
	len = strlen(value) + strlen(token) + 2;
	command = malloc(sizeof(char) * len);
	if (command == NULL){
		return (NULL);
	}
	memset(command, 0, len);
	command = strcat(command, value);
	command = strcat(command, "/");
	command = strcat(command, token);
	return (command);
}
