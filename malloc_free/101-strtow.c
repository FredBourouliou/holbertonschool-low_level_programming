#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: Number of words
 */
static int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i])
	{
		/* Skip spaces */
		while (str[i] && str[i] == ' ')
			i++;

		/* If we find a non-space character, we found a word */
		if (str[i])
			count++;

		/* Skip the word */
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

/**
 * get_word_length - Gets the length of a word
 * @str: The string containing the word
 *
 * Return: Length of the word
 */
static int get_word_length(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, words_count, word_len;

	if (str == NULL || *str == '\0')
		return (NULL);

	words_count = count_words(str);
	if (words_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (words_count + 1));
	if (words == NULL)
		return (NULL);

	for (j = 0; j < words_count; j++)
	{
		/* Skip spaces */
		while (str[i] == ' ')
			i++;

		/* Get length of current word */
		word_len = get_word_length(str + i);

		/* Allocate space for the word */
		words[j] = malloc(sizeof(char) * (word_len + 1));
		if (words[j] == NULL)
		{
			/* Free previously allocated memory if malloc fails */
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		/* Copy the word */
		for (k = 0; k < word_len; k++)
			words[j][k] = str[i + k];
		words[j][k] = '\0';

		i += word_len;
	}
	words[j] = NULL;

	return (words);
}
