#include "shell.h"

/**
 * split - A function that split and create a string command.
 * @delim: The delimiter for strtok
 * @buffer: The pointer to buffer string.
 * Return: A string.
 */

char **split(char *buffer, const char *delim)
{
	char *token = NULL, **tokens = NULL;
	size_t buffer_size = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);
	buffer_size = _strlen(buffer);
	tokens = malloc((buffer_size + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("WARNING! Unable to allocate memory");
		free(buffer);
		free_memory(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokens[i] = malloc(_strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			perror("WARNING! Unable to allocate buffer");
			free_memory(tokens);
			return (NULL);
		}
		_strcpy(tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
