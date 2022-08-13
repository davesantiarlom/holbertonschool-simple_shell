#include "shell.h"

/**
 * split - A function that split
 * @buffer: The pointer to buffer string.
 * Return: A string.
 */

char **split(char *buffer)
{
	char *token = NULL, **tokens = NULL;
	size_t buffer_size = _strlen(buffer);
	const char delim[] = " \t\n";
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * (buffer_size + 1));

	if (tokens == NULL)
	{
		perror("WARNING! Unable to allocate memory");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	return (tokens);
}
