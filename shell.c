#include "shell.h"

/**
 * main - entry point to the shell
 *
 * Return: (0) for success
 */

int main(void)
{
	struct stat statbuf;
	char **env = NULL, *buffer = NULL;
	bool pipe = false;
	size_t b_size = 0;
	ssize_t byte;

	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		pipe = true;

		display_prompt();
		byte = getline(&buffer, &b_size, stdin);

		if (byte == -1)
		{
			perror("Error (getline)");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (buffer[byte - 1] == '\n')
			buffer[byte - 1] = '\0';

		if (_strcmp(buffer, "exit") == 0)
			break;

		child_process(buffer, &statbuf, env);
	}

	free(buffer);
	return (0);
}


/**
 * _execute - exexute command input
 *
 * @arguments: arguments to be executed
 * @statbuf: structure of the buffer
 * @envp: enviromental variable
 *
 * Return: (1)
 */
int _execute(char *arguments, struct stat *statbuf, char **envp)
{
	int word_count;
	char **argv, *full_path;

	argv = split_string(arguments, " ", (int *)&word_count);
	full_path = find_path(argv[0]);

	if (full_path == NULL)
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}

	if (stat(full_path, statbuf) == -1)
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}

	execve(full_path, argv, envp);
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

/**
 * _check_file - Check if the file exist
 *
 * @filepath: check for the filepath
 * @statbuf: structure of the buffer
 *
 * Return: boolean (false)
 */
bool _check_file(char *filepath, struct stat *statbuf)
{
	int a;

	a = stat(filepath, statbuf);
	if (a == 0)
		return (true);
	return (false);
}

/**
 * split_string - split the character in the terminal
 *
 * @str: character string
 * @separators: separator of the string character
 * @word_count: number words in the string
 *
 * Return: words
 */
char **split_string(char *str, char *separators, int *word_count)
{
	int v, no_of_words;
	char **words, *str_ptr = str;
	unsigned int c, word_sizes[MAX_WORD_COUNT];

	set_zeros(word_sizes, MAX_WORD_COUNT);
	no_of_words = words_count(str, separators, word_sizes);

	words = malloc((sizeof(char *) * (no_of_words + 1)));
	if (!words)
		return (NULL);

	for (v = 0; v < no_of_words; v++)
	{
		words[v] = malloc((sizeof(char) * word_sizes[v]) + 1);
		if (!words[v])
		{
			for (v--; v >= 0; v--)
				free(words[v]);
			free(words);
			return (NULL);
		}

		for (c = 0; c < word_sizes[v]; c++, str_ptr++)
		{
			while (is_delimiter(*str_ptr, separators))
				str_ptr++;

			words[v][c] = *str_ptr;
		};

		words[v][c] = '\0';
	}

	*word_count = (int)no_of_words;

	words[v] = NULL;

	return (words);
}

/**
 * is_delimiter -  check the delimiter
 *
 * @c: the string character
 * @delimiters: the delimeter character
 *
 * Return: boolean (false)
 */
bool is_delimiter(char c, char *delimiters)
{
	int s;

	for (s = 0; delimiters[s]; s++)
	{
		if (c == delimiters[s])
			return (true);
	}
	return (false);
}
