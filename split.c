#include "shell.h"

/**
 * split - A function that split and create a string command.
 * @buffer: The pointer to buffer string.
 * Return: A string.
 */

char **split(char *buffer, const char *delim)
{
	char *token = NULL, **tokens = NULL;
	size_t buffer_size = strlen(buffer);
	/*const char delim[] = " \t\n";*/
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * (buffer_size + 1));

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
		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL){
			perror("Unable to allocate buffer");
			free_memory(tokens);
			return (NULL);
		}
		tokens[i] = token;/* strcpy(tokens[i], token); */
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	return (tokens);
}
