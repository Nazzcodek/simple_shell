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
	int w_status, word_count;
	int is_builtin = 0;
	char **argv;

	c_pid = fork();

	if (c_pid == -1)
	{
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}

	if (c_pid == 0)
	{
		argv = split_string(buffer, " ", (int *)&word_count);

		if (_strcmp(argv[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		is_builtin = builtin(argv, env);

		if (!is_builtin)
		{
			_execute(buffer, statbuf, env);
			perror("Error (execve)");
			exit(EXIT_FAILURE);
		}

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
