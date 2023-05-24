#include "shell.h"


/**
 * _env -writing the enviroment to the shell
 *
 * @sh: status of the shell
 *
 * Return: (1)
 */

int _env(status *sh)
{
	int i, j;

	for (i = 0; sh->_environ[i]; i++)
	{

		for (j = 0; sh->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, sh->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	sh->status = 0;

	return (1);
}
