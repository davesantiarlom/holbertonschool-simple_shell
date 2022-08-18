#include "shell.h"

/**
 * execute - A function that executes tokens.
 * @tokens: The pointer to split tokens
 * @buffer: The buffer of the shell.
 * @env: The pointer to the enviromental variables.
 * @counter: Number of executed cicles.
 * Return: Nothing.
 */
void execute(char **tokens, char *buffer, char **env, int counter)
{
	char **pathways = NULL, *path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(tokens[0], "env") != 0)
		print_env(env);
	if (stat(tokens[0], &st) == 0)
	{
		if (execve(tokens[0], tokens, env) < 0)
		{
			perror(buffer);
			free_memory(tokens);
      exit(EXIT_FAILURE);
		}
	}
	pathways = getPath(env);
	while (pathways[i])
	{
		path = _strcat(pathways[i], tokens[0]);
		i++;
		if (stat(path, &st) == 0)
		{
			if (execve(path, tokens, env) < 0)
			{
				perror(buffer);
				free_memory(pathways);
				free_memory(tokens);
				exit(EXIT_FAILURE);
			}
			return;
		}
	}
	messagerror(tokens, buffer, counter);
	free_memory(pathways);
}
