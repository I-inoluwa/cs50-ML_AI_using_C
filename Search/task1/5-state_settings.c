#include "main.h"

state get_state(state cur_state, state (*move)(state, char **), char **arr)
{
	state new_state = NULL;

	if (cur_state == NULL)
		return (NULL);

	new_state = move(cur_state, arr);

	return (new_state);
}

void free_state(state cur_state)
{
	if (cur_state == NULL)
		return;
	
	free(cur_state->coord);

	/*
	if (cur_state->parent == NULL)
	{
		free(cur_state);
		return;
	}
	*/
	
	free_state(cur_state->parent);
	free(cur_state);	
}

state copy_state(state cur_state)
{
	state new_state = NULL;

	if (cur_state == NULL)
		return (NULL);
	
	new_state = malloc(sizeof(position));
	new_state->c = cur_state->c;
	new_state->coord = int_copy(cur_state->coord, 2);
	new_state->parent = copy_state(cur_state->parent);

	return (new_state);
}
