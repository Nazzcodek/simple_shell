/**
 * words_count - count the number of words in an argument
 * @str: string to be counted
 * @separators: delimiter
 * @arr: number of array
 *
 * Return: word count
 */

int words_count(char *str, char *separators, unsigned int *arr)
{
unsigned int c, d, word_len = 1;
unsigned int word_count = 0;
char *str_copy = str;
bool start = false, delimiter;

/* If the string is empty */
if (!str)
return (0);

/* Shift string pointer to first non-delimiter character */
while (!start)
for (d = 0; separators[d]; d++)
(str_copy == separators[d])
str_copy++;
else
start = true;
}

/* If the string has only one character */
if (!*(str_copy + 1))
{
arr[0] = 1;
return (1);
}

for (c = 1; str_copy[c]; c++)
{
/* Compare each delimiter with the current character */
delimiter = is_delimiter(str_copy[c], separators);

/* If current char is a delimiter and previous char is not */
if (delimiter && !(is_delimiter(str_copy[c - 1], separators)))
{
arr[word_count] = word_len;
word_count++;
}

/* If we're at the end of the string and its not a delimiter */
if ((!str_copy[c + 1]) && !delimiter)
{
word_len++;
arr[word_count] = word_len;
word_count++;
break;
}
