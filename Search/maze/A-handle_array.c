#include "main.h"

size_t array_len(char **array)
{
	size_t i;

	if (array == NULL)
		return (0);

	for (i = 0; array[i] != NULL; i++)
   	;

	return (i);
}


char **array_slice(size_t ind, size_t jnd, char **array)
{
	size_t i, len = array_len(array);
	char **new_array = NULL;

	if (array == NULL || ind > len || jnd > len || ind > jnd)
		return (array);

	new_array = malloc(sizeof(char *) * (jnd - ind + 2));
	if (new_array == NULL)
	{
		free(new_array);
		return (NULL);
	}

	for (i = 0; i <= (jnd - ind); i++)
	{
		new_array[i] = _strdup(array[ind + i]);
	}
	new_array[i] = NULL;

	return (new_array);
}

char *_strdup(char *str)
{
	char *s;
	int i, strrlen;

	if (str == NULL)
		return (NULL);
	strrlen = 0;
	for (i = 0; str[i]; i++)
	{
		strrlen++;
	}
	s = malloc((strrlen + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';

	return (s);
}

void free_arr(char **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}

void free_int_arr(int **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
