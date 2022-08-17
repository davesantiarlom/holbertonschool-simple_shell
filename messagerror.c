#include "shell.h"

/**
 * messagerror - A function that prints message not found.
 * @buffer: The buffer of the shell.
 * @counter: Number of counter.
 * @tokens: The pointer to tokenized tokens.
 * Return: Nothing.
 */
void messagerror(char **tokens, char *buffer, int counter)
{
	char c = counter + '0';
	write(STDOUT_FILENO, buffer, _strlen(buffer));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDOUT_FILENO, ": Not Found\n", 12);
}
