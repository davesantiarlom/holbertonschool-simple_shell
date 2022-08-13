#include "shell.h"

/**
* free_memory - A function that frees all the memory allocated.
* @command: The pointer to allocated memory to free.
* Return: Nothing.
*/

void free_memory(char **command){
	size_t i = 0;

	if (command == NULL)
		return;
	while (command[i]){
	free(command[i]);
		i++;
	}

	if (command[i] == NULL)
	free(command[i]);
	free(command);
}

/**
* shell_exit - A function that exits the shell.
* @command: The pointer to tokenized command.
* Return: Nothing.
*/

void shell_exit(char **command){
	int status = 0;
	if (command[1] == NULL){
		free_dp(command);
		exit(EXIT_SUCCESS);
	}
	status = _atoi(command[1]);
	free_dp(command);
	exit(status);
}
