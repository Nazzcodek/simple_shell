#include "shell.h"

/**
 * find_path - Find path to arguments
 *
 * @command: command to search for path
 *
 * Return: NULL
 */
char* find_path(char* command)
{
	char* full_path = _getenv("PATH");
	char* file_path;

	if (full_path)
	{
		file_path = iterate_paths(full_path, command);
			return (file_path);
	}

	return (NULL);
}
/**
 * iterate_paths - look throught the path
 *
 * @full_path: full path of the command
 * @command: the command to be looked for
 *
 * Return: NULL
 */
char* iterate_paths(char* full_path, char* command)
{
	char* full_path_copy = _strdup(full_path);
	char* path_token = strtok(full_path_copy, ":");

	while (path_token != NULL)
	{
		char* file_path = create_file_path(path_token, command);
		if (access(file_path, X_OK) == 0)
		{
			free(full_path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}

	free(full_path_copy);
	return (NULL);
}

/**
 * create_file_path - Create the full path to argument
 *
 * @path_token: token to the path
 * @command: command to be executed
 *
 * Return: full path
 */
char* create_file_path(char* path_token, char* command)
{
	int command_len = _strlen(command);
	int dir_len = _strlen(path_token);
	char* file_path = malloc(command_len + dir_len + 2);

	_strcpy(file_path, path_token);
	_strcat(file_path, "/");
	_strcat(file_path, command);
	_strcat(file_path, "\0");

	return (file_path);
}

/**
 * _getenv - get the environmental variable
 *
 * @name: variable
 *
 * Return: NULL
 */
char* _getenv(const char* name)
{
	extern char** environ;
	char* env;
	int j = 0, i;
	
	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; ++i)
	{
		env = environ[i];

		while (name[j] != '\0' && env[j] == name[j])
			++j;

		if (name[j] == '\0' && env[j] == '=')
			return (&env[j + 1]);
	}

	return (NULL);
}
