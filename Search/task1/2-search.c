#include "main.h"

frontier_ stack_algorithm(char **arr, frontier_ frontier, state *goal_states)
{
	state cur_state = NULL, goal = NULL, pos_state = NULL;
	frontier_ explored = NULL, new_frontier = NULL;
	int ind = 0, i = 0, j = 0, end = 0;
	int len = len_frontier(goal_states);

	state (*move[4])(state, char **) = {
		up,
		right,
		down,
		left
		};

	if (arr == NULL || frontier == NULL)
		return (NULL);

	while (1)
	{
		cur_state = copy_state(frontier[len_frontier(frontier) - 1]);
		new_frontier = copy_frontier_pop(frontier);
		free_frontier(frontier);
		frontier = new_frontier;

		if (!(in_explored(cur_state, explored)))
			explored = add_state(cur_state, explored);
		for (i = 0; i < len; i++)
		{
			goal = goal_states[i];
			if (state_match(cur_state, goal))
			{
				printf("GOAL REACHED!\n\n");
				printf("\nGoal at {%d, %d}.\n", (goal->coord)[0], (goal->coord)[1]);
				free_state(cur_state);
				end = 1;
				break;
			}
		}

		if (end == 1)
			break;

		for (ind = 0; ind < 4; ind++)
		{
			pos_state = move[ind](cur_state, arr);
			if (pos_state != NULL)
			{
				if ((pos_state->c == '.') && (!(in_explored(pos_state, explored))))
					frontier = add_state(pos_state, frontier);
			}
			free_state(pos_state);
		}

		free_state(cur_state);
		if (empty(frontier))
		{
			printf("SOLUTION COULD NOT BE FOUND\n");
			break;
		}
	}
	free_frontier(frontier);

	if (end == 1)
		return (explored);

	return (NULL);
}

frontier_ push(frontier_ new_ft, frontier_ old_ft)
{
	int len1 = len_frontier(new_ft), len2 = len_frontier(old_ft);
	int i = 0, len = len1 + len2 + 1;
	frontier_ merged = NULL;

	if (old_ft == NULL)
		return (new_ft);
	if (new_ft == NULL)
		return (NULL);

	merged = malloc(sizeof(position) * len);

	for (i = 0; i < len2; i++)
	{
		merged[i] = copy_state(old_ft[i]);
	}
	free_frontier(old_ft);

	for (i = len2; i < len; i++)
	{
		merged[i] = copy_state(new_ft[i - len2]);
	}
	free_frontier(new_ft);
	merged[i] = NULL;

	return (merged);
}
