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


int len_frontier(frontier_ frontier)
{
	int ind = 0;

	if (frontier == NULL)
		return (0);

	for (ind  = 0; frontier[ind] != NULL; ind++)
	;

	return (ind);
}

frontier_ copy_frontier_pop(frontier_ frontier)
{
	int len = len_frontier(frontier), i = 0;
	frontier_ new_frontier = NULL;

	if (frontier == NULL)
		return (NULL);
	
	new_frontier = malloc(sizeof(position) * (len));
	for (i = 0; i < len - 1; i ++)
	{
		new_frontier[i] = copy_state(frontier[i]);
	}
	new_frontier[i] = NULL;

	return (new_frontier);
}

int empty(frontier_ frontier)
{
	int i = 0, len = len_frontier(frontier);

	if (frontier == NULL || frontier[0] == NULL)
		return (1);

	return (0);
}
