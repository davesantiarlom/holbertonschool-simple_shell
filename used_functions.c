#include "shell.h"

/**
 * _strlen - A function that finds the length of the string
 * @s: The input string
 * Return: The length of the string
 */
int _strlen(char *s)
{
	unsigned int lenght = 0;

	while (s[lenght])
		lenght++;
	return (lenght);
}

/**
 * _atoi - Convert string into an integer
 * @string: string to convert to int
 * Return: The int the stringing represents,
 */
int _atoi(char *string)
{
	int i = 0, number = 0;

	while (string[i] != '\0')
	{
		if (string[i] < '0' || string[i] > '9')
			return (-1);
		number = number * 10 + string[i] - '0';
		i++;
	}
	return (number);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, or -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - a function that compares two strings.
 * @str1: an input string
 * @str2: an input string
 * Return: The difference s1 - s2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++, str2++;
	}
	return (*str1 - *str2);
}
