#include "main.h"

/**
 * cmd_builtin - function for builtin commands
 * @args: arguments
 * @n: number of argument
 * @command: command
 * @env: variable environment
 *
 * Return: 0 Always success
 */

int cmd_builtin(char **args, int n, char *command, char **env)
{
	(void) n;
	(void) command;

	if (strcmp(args[0], env) == 0)
	{
		env(env_call);
		return (1);
	}
	return (0);
}
