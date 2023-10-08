#include "main.h"

size_t _strlen(const char *s)
{
	size_t length = 0;

	if (s == NULL)
		return (0);

	if (s[0] == '\0')
		return (0);

	while (s[length])
	{
		length++;
	}

	return (length);
}

char **split_str(char *str, char *delim)
{
	char **array;
	int word_count = check_space(str, delim), itr = 0, i = 0, j;
	int *str_len;

	if (str == NULL || delim == NULL || word_count == 0)
		return (NULL);
	if ((array = malloc(sizeof(char *) * (word_count + 1))) == NULL)
		return (NULL);

	array[word_count] = NULL;
	while (str[itr])
	{
		str_len = get_str_len_alt(str, itr, delim);
		if (str_len[0] == 0)
		{
			itr += str_len[1];
			free(str_len);
			continue;
		}
		
		*(array + i) = malloc(sizeof(char) * (str_len[0] + 1));
		if(*(array + i) == NULL)
		{
			free(str_len);
			return (NULL);
		}

		for (j = 0; j < (str_len[0] + str_len[1]); j++, itr++)
		{
			if (is_delim(str[itr], delim))
			{
				continue;
			}
			array[i][j - str_len[1]] = str[itr];
		}
		array[i][str_len[0]] = '\0';
		free(str_len);
		++i;
	}
	return (array);
}


int *get_str_len_alt(char *str, int ix, char *delim)
{
	int i = 0, keep = ix;
	int *save_ind = malloc(sizeof(int) * 2);

	if (save_ind == NULL || str == NULL || str[0] == 10)
	{
		free(save_ind);
		return (NULL);
	}
	
	while(str[i + ix])
	{
		if (is_delim(str[i + ix], delim))
		{
			++ix;
			continue;
		}

		if (!(is_delim(str[i + ix], delim)))
		{
			++i;
		}

		if (is_delim(str[i + ix], delim))
		{
			break;
		}
	}

	save_ind[0] = i;
	save_ind[1] = ix - keep;
	return (save_ind);
}


int is_delim(char c, char *delim)
{
	int i;

	for(i = 0; delim[i]; i++)
	{
		if (c == delim[i])
			return (1);
	}
	
	return (0);
}


int check_space(char *str, char *delim)
{
	int i;
	int count_words = 0;
	if (str == NULL || delim == NULL)
		return (0);
	
	for (i = 0; str[i]; i++)
	{
		if (is_delim(str[i], delim))
		;

		else if (is_delim(str[i + 1], delim) || str[i + 1] == '\0')
		{
			++count_words;
		}
	}

	return (count_words);
}
