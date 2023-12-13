#include "main.h"

/**
 * process_prompt - Process user input
 * @argv: argument vector
 * @command: command from user
 * @env: variable of environment
 *
 * Return: Always 0 if success
 */

void process_prompt(char *argv[], char *command, char **env)
{
	int n, status;
	char *args[10];
	char *file, *file_copy;
	pid_t child_pid;

	file_copy = argv[0];
	n = cmd_token(command, args);

	if (n == 0)
	{
		return;
	}

	if (cmd_builtin(args, n, command, env) == 1)
	{
		return;
	}
	file = find_path(args[0]);
	child_pid = fork();

	if (child_pid == 1)
	{
		perror("Error");
		free(command);
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(file, args, NULL) == -1)
		{
			write(2, file, strlen(file));
			write(2, ": 1 :", 5);
			write(2, args[0], strlen(args[0]));
			write(2, ": not found\n", 12);
			exit(127);
		}
	}
	else
		wait(&status);
	free(file);
}
