#include "shell.h"


/**
 * env -writing the enviroment to the shell
 *
 * Return: void
 */

void _env(void)
{
	int i;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
