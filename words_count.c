#include "shell.h"

/**
 * shift_string - shifting the string pointer
 *
 * @str: string to be shifted
 * @separators: String separators
 *
 * Return: d
 */
unsigned int shift_string(char **str, char *separators)
{
	unsigned int d;
	bool start = false;

	while (!start)
	{
		for (d = 0; separators[d]; d++)
		{
			if (**str == separators[d])
				(*str)++;
			else
				start = true;
		}
	}

	return (d);
}

/**
 * words_count - Counting of words in a string
 *
 * @str: string to be counted
 * @separators: delimiter
 * @arr: array of string
 *
 * Return: word count
 */
unsigned int words_count(char *str, char *separators, unsigned int *arr)
{
	unsigned int c, word_len = 1, word_count = 0;
	char *str_copy = str;
	bool delimiter;


	if (!str)
		return (0);

	shift_string(&str_copy, separators);

	if (!*(str_copy + 1))
	{
		arr[0] = 1;
		return (1);
	}

	for (c = 1; str_copy[c]; c++)
	{
		delimiter = is_delimiter(str_copy[c], separators);

		if (delimiter && !(is_delimiter(str_copy[c - 1], separators)))
		{
			arr[word_count] = word_len;
			word_count++;
		}

		if ((!str_copy[c + 1]) && !delimiter)
		{
			word_len++;
			arr[word_count] = word_len;
			word_count++;
			break;
		}

		if (!delimiter)
			word_len++;
		else
			word_len = 0;
	}

	return (word_count);
}
/**
 * free_split_string - free string that has been splited
 *
 * @words: string to be splited
 * @word_count: number of words in string
 *
 * Return: words
 */
void free_split_string(char **words, int word_count)
{
	int i;

	if (words == NULL)
		return;

	for (i = 0; i < word_count; i++)
		free(words[i]);

	free(words);
}

