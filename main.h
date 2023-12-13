#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char *find_path(char *file);
char *locate_file(char *path, char *file);
void process_prompt(char *command, char *argv[], char **env);
void prompt(void);
char prompt_cmd(void);
int cmd_token(char *command, char *args[]);
void env(char **env);
int cmd_builtin(char **args, int n, char *command, char **env);

#endif /* MAIN_H */
