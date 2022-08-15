#include "shell.h"

/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, lenght = 0;

	while (env[i])
	{
		lenght = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], lenght);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
