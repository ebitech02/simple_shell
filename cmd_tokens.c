#include "main.h"

/**
 * cmd_token - tokenize the command strings
 * @args: string array
 * @command: user input
 *
 * Return: tokens
 */

int cmd_token(char *args[], char *command)
{
	char *token;
	int n;

	n = 0;
	token = strtok(command, " \n");

	while (token)
	{
		args[n] = token;
		token = strtok(NULL, " \n");
		n++;
	}

	args[n] = NULL;
	return (n);
}
