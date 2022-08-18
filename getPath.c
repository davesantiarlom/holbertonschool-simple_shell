#include "shell.h"

/**
 * getPath - A function to gets value from.
 * env variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All split pathways for tokens.
 */
char **getPath(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = split(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}
