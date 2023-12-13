#include "main.h"

/**
 * env - environment variable
 * @env: argument
 *
 * Return void
 */

void env_call(const char *env)
{
	while (*env != NULL)
	{
		size_t length = strlen(*env);
		write(1, *env, length);
		write(1, "\n", 1);
		env++;
	}
}
