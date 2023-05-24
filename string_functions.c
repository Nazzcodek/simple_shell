#include "shell.h"

/**
 * _strncmp - comapares string
 * @s1: pointer to character
 * @s2: pointer to character
 * @n: size of integer
 *
 * Return: 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
/**
 * _strlen - the length of the string
 * @s: pointer to the string
 *
 * Return: length
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);

	for (length = 0; s[length]; lenght++)
		;
	return (length);
}
/**
 * _strcpy - copies the string
 * @dest: destination of string to be copied
 * @src: source of the string
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatenate string
 * @dest: destination of the string
 * @src: source of string
 * Return: 0
 *
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}
/**
 * _strdup - duplicate string
 * @str: string to duplicate
 *
 * Return: NULL
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *copy = malloc(len);

	if (copy != NULL)
		_strcpy(copy, str);
}
