#include "shell.h"

/**
* free_memory - A function that frees all the memory allocated.
* @tokens: The pointer to allocated memory to free.
* Return: Nothing.
*/

void free_memory(char **tokens)
{
	size_t i = 0;

	if (tokens == NULL)
		return;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}

	if (tokens[i] == NULL)
		free(tokens[i]);
	free(tokens);
}
