#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

/* Builtin Struct
 * struct builtins_s - Struct for builtins names to the function
 * @name: Name of the builtin
 * @func: Pointer to function to call when name is bufferted
 */
typedef struct builtin{
	char *name;
	int (*func)();
} builtin;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char **split(char *buffer);
void handle(int signals);
void shell_exit(char **command);
void free_memory(char **command);

#endif
