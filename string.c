#include "shell.h"

/**
 * free_string_array - frees the string array
 * @array: pointer to array
 * @size: size of the array
 *
 * Return: NULL
 */


void free_string_array(char **array, int size)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
}
/**
 * _strcmp -compares string
 * @s1: string to character
 * @s2: string to character
 *
 * Return: 0
 */
int _strcmp(const char *s1, const char *s2)
{
	int result = 0;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
/**
 * _strchr - string character
 * @str: string
 *@c: integer to the string
 * Return: Null
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (char *str);
		str++;
	}
	if (c == '\0')
		return (char *str);

	return (NULL);
}
