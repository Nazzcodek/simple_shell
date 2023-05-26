#include "shell.h"

/**
 * child_process - get the child process
 * @buffer: string character
 * @statbuf: buffer structure
 * @env: enviroment
 *
 * Return: nothing
 */

void child_process(char *buffer, struct stat *statbuf, char **env)
{
	pid_t c_pid;
	int w_status;
	char *path;

	path = find_path(buffer);
	if (path == NULL)
	{
		perror("./hsh");
	}
	else
		c_pid = fork();

	if (c_pid == -1)
	{
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}

	if (c_pid == 0)
	{
		_execute(buffer, statbuf, env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(c_pid, &w_status, 0) == -1)
		{
			perror("Error (waitpid)");
			exit(EXIT_FAILURE);
		}
	}
}
