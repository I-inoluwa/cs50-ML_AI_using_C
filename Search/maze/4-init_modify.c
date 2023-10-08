#include "main.h"

frontier_ add_state(state new_state, frontier_ frontier)
{
	frontier_ new_frontier = NULL;
	int len = len_frontier(frontier), i = 0;

	new_frontier = malloc(sizeof(position) * (len + 2));
	if (new_frontier == NULL)
		return (frontier);

	new_frontier[len + 1] = NULL;
	if (frontier == NULL)
	{
		new_frontier[0] = copy_state(new_state);
		return new_frontier;
	}

	for (i = 0; i < len; i++)
	{
		new_frontier[i] = copy_state(frontier[i]);
	}
	new_frontier[i] = copy_state(new_state);

	free_frontier(frontier);
	return (new_frontier);
}

frontier_ initialize(char **arr)
{
	state init_state = NULL;
	frontier_ frontier = NULL;
	int i_pos[3] = {15, 0, -1};

	if (arr == NULL)
		return (NULL);

	init_state = malloc(sizeof(position));
	if (init_state == NULL)
		return (NULL);

	init_state->c = arr[i_pos[0]][i_pos[1]];
	init_state->coord = int_copy(i_pos, 2);
	init_state->parent = NULL;

	frontier = add_state(init_state, frontier);
	free_state(init_state);

	return (frontier);
}

state pop(frontier_ *frontier)
{
	frontier_ new_frontier = NULL;
	state popped = NULL;

	if (*frontier == NULL)
		return (NULL);

	popped = copy_state(*frontier[len_frontier(*frontier) - 1]);
	new_frontier = copy_frontier_pop(*frontier);
	free_frontier(*frontier);
	*frontier = new_frontier;

	return (popped);
}

state set_goal_state(int *coord, char **arr)
{
	state goal_state = NULL;

	if (coord == NULL || arr == NULL)
		return (NULL);

	goal_state = malloc(sizeof(position));
	if (goal_state == NULL)
		return (NULL);

	goal_state->c = arr[coord[0]][coord[1]];
	goal_state->coord = int_copy(coord, 2);
	goal_state->parent = NULL;

	return goal_state;
}
