#include "main.h"

void free_frontier(frontier_ frontier)
{
	int i = 0;

	if (empty(frontier))
	{
		free(frontier);
		return;
	}

	for (i = 0; frontier[i] != NULL; i++)
	{
		free_state(frontier[i]);
	}

	free(frontier);
}

frontier_ copy_frontier_pop(frontier_ frontier)
{
	int len = len_frontier(frontier), i = 0;
	frontier_ new_frontier = NULL;

	if (frontier == NULL)
		return (NULL);

	new_frontier = malloc(sizeof(position) * (len));
	for (i = 0; i < len - 1; i++)
	{
		new_frontier[i] = copy_state(frontier[i]);
	}
	new_frontier[i] = NULL;

	return (new_frontier);
}

frontier_ remove_state(frontier_ frontier, state max)
{
	int len = len_frontier(frontier), i = 0, j = 0;
	frontier_ new_frontier = NULL;

	if (frontier == NULL)
		return (NULL);

	new_frontier = malloc(sizeof(position) * (len));
	for (i = 0; i < len; i++)
	{
		if (state_match(frontier[i], max))
			continue;
		new_frontier[j] = copy_state(frontier[i]);
		j++;
	}
	new_frontier[j] = NULL;

	return (new_frontier);
}

frontier_ copy_frontier(frontier_ frontier)
{
	int len = len_frontier(frontier), i = 0;
	frontier_ new_frontier = NULL;

	if (frontier == NULL)
		return (NULL);

	new_frontier = malloc(sizeof(position) * (len + 1));
	for (i = 0; i < len; i++)
	{
		new_frontier[i] = copy_state(frontier[i]);
	}
	new_frontier[i] = NULL;

	return (new_frontier);
}
