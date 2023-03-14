#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words in
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int i, count = 0, in_word = 0;

	for (i = 0; str[i] != '\0'; ++i)
		{
		if (str[i] == ' ')
		{
			if (in_word)
			{
				++count;
				in_word = 0;
			}
		}
		else
		{
			in_word = 1;
		}
	}

	if (in_word)
	{
		++count;
	}

	return count;
}

/**
 * strtow - Splits a string into word
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or 
 * NULL if str == NULL or str == ""
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, num_words, word_len;

	if (str == NULL || *str == '\0')
	{
		return NULL;
	}

	num_words = count_words(str);
	words = malloc(sizeof(char *) * (num_words + 1));

	if (words == NULL)
	{
		return NULL;
	}

	for (i = 0, j = 0; i < num_words; ++i)
	{
		while (str[j] == ' ')
		{
			++j;
		}

		word_len = 0;

		while (str[j + word_len] != ' ' && str[j + word_len] != '\0')
		{
			++word_len;
		}

		words[i] = malloc(sizeof(char) * (word_len + 1));

		if (words[i] == NULL)
		{
		for (k = 0; k < i; ++k)
		{
			free(words[k]);
		}
		free(words);
		return NULL;
		}

		strncpy(words[i], &str[j], word_len);
		words[i][word_len] = '\0';
		j += word_len;
	}

	words[num_words] = NULL;

	return words;
}
