#include "shell.h"

/**
 * builtin - executing builtin functions
 *
 * @argv: built in argument vector
 * @env: environment
 *
 * Return: (0)
 */

int builtin(char **argv, char **env)
{
	if (_strcmp(argv[0], "cd") == 0)
	{
		cd(argv, env);
		free(argv);
		return (1);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		free(argv);
		return (1);
	}
	return (0);
}
/**
 * _env - enviromental variable
 */
void _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_put(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * cd - change directory
 *
 * @argv: pointer to argument vector
 * @env: environment
 */
void cd(char **argv, char **env)
{
	int i = 0;
	char *dir = NULL, d[1024];

	while (argv[i])
		i++;

	if (i == 1 && argv[1] == NULL)
	{
		dir = _getenv("HOME");
		if (chdir(dir) == -1)
			perror(argv[0]);
		else
			set_pwd(env, dir);
	}
	else if (strcmp(argv[1], "-") == 0 && i == 2)
	{
		dir = _getenv("OLDPWD");
		if (chdir(dir) == -1)
			perror(argv[0]);
		else
			set_pwd(env, dir);
	}
	else if (i == 2)
	{
		if (chdir(argv[1]) == -1)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			getcwd(d, 1024);
			set_pwd(env, d);
		}
	}
	else
	{
		perror("ERROR (_strlen)");
		exit(EXIT_FAILURE);
	}
}
