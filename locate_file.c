#include "main.h"

/**
 * locate_file - get the path of the file
 * @path: variable
 * @file: file variable
 *
 * Return: the path to the file
 */

char *locate_file(char *path, char *file)
{
	char *dup_path;
	char *token;
	char *path_buffer = NULL;
	struct stat buffer;

	dup_path = strdup(path);
	token = strtok(dup_path, ":");
	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(file) + 2);
		if (!path_buffer)
		{
			perror("Error: failed to find path");
			exit(1);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, file);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &buffer) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(dup_path);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(dup_path);
	if (path_buffer)
	{
		free(path_buffer);
	}
	return (NULL);
}
