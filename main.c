#include "main.h"

/**
 * main - entry point of program
 * @argc: argument count
 * @argv: argument vector
 * @env: variable to environment
 *
 * Return: Always 0 if success
 */

int main(int argc, char *argv[], char **env)
{
	(void) argc;
	char *cmd_buf;

	while (1)
	{
		prompt();
		cmd_buf = process_cmd();
		process_prompt(cmd_buf, argv, env);
		free(cmd_buf);
	}

	return (0);
}

/**
 * prompt - get command from user
 *
 * Return: user prompt
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$");
	}
}

/**
 * prompt_cmd - process user command
 *
 * Return: user command prompt
 */

char *prompt_cmd(void)
{
	ssize_t nread;
	size_t buf_size;
	char *cmd_buf;

	cmd_buf = NULL;
	buf_size = 0;
	nread = getline(&cmd_buf, &buf_size, stdin);

	if (nread == -1)
	{
		free(cmd_buf);
		exit(0);
	}

	return (cmd_buf);
}
