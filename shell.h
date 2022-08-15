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

int main(int ac, char **av, char **env);
char **split(char *buffer, const char *delim);
void free_memory(char **tokens);
void check_EOF(char *buffer);
void shell_exit(char **tokens);
void execute(char **tokens, char *buffer, char **env, int counter);
void create_child(char **tokens, char *buffer, char **env, int counter);
void print_env(char **env);
char **_getPATH(char **env);
void messagerror(char **tokens, char *buffer, int counter);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

#endif
