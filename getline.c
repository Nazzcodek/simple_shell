#include "shell.h"

/**
 * _get_line - reads the entire line
 * @p: pointer to character
 * @q: pointer to character
 * @r: pointer to character
 * @n: pointer to character
 * @ending_buf: pointer to buffer
 *
 * Return: Null
 */

ssize_t _get_line(char **p, char *q, char *r, char *ending_buf, size_t *n)
{
	ssize_t read_count = 1, read_count_total = 0;

	while (read_count != 0)
	{
		read_count = read(STDIN_FILENO, r, 1);
		if (read_count == -1)
			return (-1);

		read_count_total += read_count;

		if (*r == '\n')
			break;

		if (r == ending_buf)
		{
			size_t new_size = *n * 2;
			char *new_buf = _realloc(q, *n, new_size);

			if (new_buf == NULL)
				return (-1);
			q = new_buf;
			*p = q;
			r = q + *n - 1;
			ending_buf = q + new_size;
			*n = new_size;
		}

		r++;
	}

	r++;
	*r = '\0';
	*p = q;

	return (read_count_total);
}
/**
 * _getline - reads the entire line
 * @lineptr: pointer to the line
 * @n: pointer to size
 * @stream: pointer to stream
 *
 * Return: NULL
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_count_total;
	char *buf, *moving_buf, *ending_buf;

	if (!lineptr || !n || !stream)
		return (-1);
	fflush(stdout);
	if (*lineptr == NULL && *n == 0)
	{
		*n = CHAR;
		buf = malloc(*n);
		if (buf == NULL)
			return (-1);
		*lineptr = buf;
	}
	else
		buf = *lineptr;

	moving_buf = buf;
	ending_buf = buf + *n;

	read_count_total = _get_line(lineptr, buf, moving_buf, ending_buf, n);

	return (read_count_total);
}
