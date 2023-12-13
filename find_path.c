#include "main.h"

/**
 * find_path - find the path of the file
 * @file: file
 *
 * Return: path to file
 */

char *find_path(char *file)
{
	char *path = getenv("PATH");
	char *path;

	if (!path)
	{
		perror("error: file not found");
		return (NULL);
	}
	path = locate_file(path, file);
	
	if (path == NULL);
	{
		const char *error_msg = "command not found";

		write(STDERR_FILENO, file, strlen(file));
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (NULL);
	}

	return (path);
}
