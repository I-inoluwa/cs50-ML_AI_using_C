#include "main.h"

state move_template(state cur_state)
{
	state new_state = NULL;

	if (cur_state == NULL)
		return (NULL);

	new_state = malloc(sizeof(position));
	if (new_state == NULL)
		return (NULL);

	new_state->c = cur_state->c;
	new_state->coord = int_copy(cur_state->coord, 2);
	new_state->parent = NULL;

	return (new_state);
}

state up(state cur_state, char **arr)
{
	int x = 0, y = 0;
	state new_state = NULL;

	new_state = move_template(cur_state);
	if (new_state == NULL)
		return (NULL);

	x = (cur_state->coord)[0], y = (cur_state->coord)[1];

	if (x == 0)
	{
		free_state(new_state);
		return (NULL);
	}

	(new_state->coord)[0] = x - 1;
	new_state->c = arr[x - 1][y];
	new_state->parent = copy_state(cur_state);

	return (new_state);
}

state down(state cur_state, char **arr)
{
	int x = 0, y = 0;
	state new_state = NULL;

	new_state = move_template(cur_state);
	if (new_state == NULL)
		return (NULL);

	x = (cur_state->coord)[0], y = (cur_state->coord)[1];

	if (arr[x + 1] == NULL)
	{
		free_state(new_state);
		return (NULL);
	}

	(new_state->coord)[0] = x + 1;
	new_state->c = arr[x + 1][y];
	new_state->parent = copy_state(cur_state);

	return (new_state);
}

state left(state cur_state, char **arr)
{
	int x = 0, y = 0;
	state new_state = NULL;

	new_state = move_template(cur_state);
	if (new_state == NULL)
		return (NULL);

	x = (cur_state->coord)[0], y = (cur_state->coord)[1];

	if (y == 0)
	{
		free_state(new_state);
		return (NULL);
	}

	(new_state->coord)[1] = y - 1;
	new_state->c = arr[x][y - 1];
	new_state->parent = copy_state(cur_state);

	return (new_state);
}

state right(state cur_state, char **arr)
{
	int x = 0, y = 0;
	state new_state = NULL;

	new_state = move_template(cur_state);
	if (new_state == NULL)
		return (NULL);

	x = (cur_state->coord)[0], y = (cur_state->coord)[1];

	if (arr[x][y + 1] == '\0')
	{
		free_state(new_state);
		return (NULL);
	}

	(new_state->coord)[1] = y + 1;
	new_state->c = arr[x][y + 1];
	new_state->parent = copy_state(cur_state);

	return (new_state);
}
