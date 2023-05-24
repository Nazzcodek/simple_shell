#include "shell.h"

/**
 * display_prompt - displays input
 *
 */
void display_prompt(void)
{
	char *prompt = "cisfun$ ";

	write(STDIN_FILENO, prompt, 8);
}
/**
 * read_command - reads the command
 * Return: buffer
 */
char *read_command()
{
	char *buffer = NULL;
	size_t b_size = 0;
	ssize_t byte;

	byte = getline(&buffer, &b_size, stdin);

	if (byte == -1)
	{
		perror("Error (getline)");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	if (buffer[byte - 1] == '\n')
		buffer[byte - 1] = '\0';

	return (buffer);
}
/**
 * execute_fork - execute the parent child process
 * @argv: pointer to argument
 * @envp: pointer to environment
 */
void execute_fork(char **argv, char **envp)
{
	pid_t c_pid;
	int w_status;

	c_pid = fork();

	if (c_pid == -1)
	{
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}

	if (c_pid == 0)
	{
		execve(argv[0], argv, envp);
		perror("Error (execve)");
		exit(EXIT_FAILURE);
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
