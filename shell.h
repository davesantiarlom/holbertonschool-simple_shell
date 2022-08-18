#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env);
char **split(char *buffer, const char *delim);
void free_memory(char **tokens);
void execute(char **tokens, char *buffer, char **env, int counter);
void create_child(char **tokens, char *buffer, char **env, int counter);
void print_env(char **env);
char **getPath(char **env);
void messagerror(char **tokens, char *buffer, int counter);

/* String Functions */
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
