#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL if str is NULL or empty.
 */
char **strtow(char *str)
{
	char **words;
	size_t i, j, k, word_count = 0, word_len = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			word_count++;
	}

	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			word_len++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				words[j] = malloc((word_len + 1) * sizeof(char));
				if (words[j] == NULL)
				{
					for (k = 0; k < j; k++)
						free(words[k]);
					free(words);
					return (NULL);
				}

				for (k = 0; k < word_len; k++)
					words[j][k] = str[i - word_len + 1 + k];
				words[j][k] = '\0';
				j++;
				word_len = 0;
			}
		}
	}

	words[word_count] = NULL;
	return (words);
}

