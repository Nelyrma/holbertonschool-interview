#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * match_words - check if substring matches all words
 * @str: substring from s
 * @words: list of words
 * @nb_words: number of words
 * @word_len: length of one word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int match_words(const char *str, const char **words,
		int nb_words, int word_len)
{
	int *used, i, j, found = 0;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(str + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * find_substring - find all starting indices of substrings formed by words
 * @s: input string
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to number of results
 *
 * Return: array of indices, or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, total_len, s_len, i, count = 0;
	int *res;

	if (!s || !words || nb_words == 0)
		return (NULL);

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = strlen(s);

	res = malloc(sizeof(int) * (s_len));
	if (!res)
		return (NULL);

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (match_words(s + i, words, nb_words, word_len))
			res[count++] = i;
	}

	if (count == 0)
	{
		free(res);
		*n = 0;
		return (NULL);
	}

	*n = count;
	return (res);
}
