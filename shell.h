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

int main(int ac, char **av, char **env);
char **split(char *buffer, const char *delim);
void free_memory(char **tokens);
void shell_exit(char **tokens);
void execute(char **tokens, char *buffer, char **env, int counter);
void create_child(char **tokens, char *buffer, char **env, int counter);
void print_env(char **env);
char **_getPATH(char **env);
void messagerror(char **tokens, char *buffer, int counter);

#endif
