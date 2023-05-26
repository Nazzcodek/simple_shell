#include "shell.h"


/**
 * _var - variable
 *
 * @name: name of variable
 * @value: value of variable
 * @env: environment variable
 *
 * Return: (1)
 */

int _var(char *name, char *value, char **env)
{
	int j = 0;
	char *cpy, *equal_sign, *new_var;
	size_t new_var_len;

	while (env[j])
	{
		cpy = _strdup(env[j]);
		equal_sign = _strchr(cpy, '=');

		if (equal_sign != NULL)
		{
			*equal_sign = '\0';
			if (_strcmp(cpy, name) == 0)
			{
				new_var_len = _strlen(name) + _strlen(value) + 2;
				new_var = malloc(sizeof(char) * new_var_len);
				if (new_var == NULL)
				{
					free(cpy);
					return (-1);
				}

				_strcpy(new_var, name);
				_strcat(new_var, "=");
				_strcat(new_var, value);

				free(env[j]);
				env[j] = new_var;
				free(cpy);

				return (0);
			}
		}

		free(cpy);
		j++;
	}

	return (-1);
}

/**
 * set_pwd - set working directory
 *
 * @env: environment variable
 * @current: current directory
 *
 * Return: (0) success
 */

int set_pwd(char **env, char *current)
{
	char *old_pwd;

	old_pwd = _getenv("PWD");

	if (old_pwd == NULL)
		return  (-1);

	if (_var("PWD", current, env) == -1 || _var("OLDPWD", old_pwd, env) == -1)
		return (-1);

	return (0);
}
