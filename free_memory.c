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

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}

	if (tokens[i] == NULL)
		free(tokens[i]);
	free(tokens);
}

/**
 * shell_exit - A function that exits the shell.
 * @tokens: The pointer to split tokens.
 * Return: Nothing.
 */
void shell_exit(char **tokens){
	int status = 0;
	if (tokens[1] == NULL){
		free_memory(tokens);
		exit(EXIT_SUCCESS);
	}
	status = _atoi(tokens[1]);
	free_memory(tokens);
	exit(status);
}
