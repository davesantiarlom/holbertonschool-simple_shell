#include "shell.h"

/**
 * create_child - A function that creates a sub process.
 * @tokens: The pointer to tokenized tokens
 * @buffer: The pointer to the buffer of shell.
 * @env: The pointer to the enviromental variables.
 * @counter: Number of executed counter.
 * Return: Nothing.
 */
void create_child(char **tokens, char *buffer, char **env, int counter)
{
	int pid = fork();
	int status = 0, wait_error = 0;

	if (pid < 0){
		perror("Error: Out of place");
		free_memory(tokens);
		exit(EXIT_FAILURE);
	}
	if (pid == 0){
		execute(tokens, buffer, env, counter);
		free_memory(tokens);
	}
	wait_error = waitpid(pid, &status, 0);
	if (wait_error < 0){
		free_memory(tokens);
		exit(EXIT_FAILURE);
	}
	free_memory(tokens);
}
